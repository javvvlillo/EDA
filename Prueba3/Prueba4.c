#include <stdio.h>
#include <stdlib.h>
#include "Prueba4.h"

char labels[5] = {'A', 'B','C','D','E'};

struct tree_node *crear_nodo_tree(char label) //arbol
{
    struct tree_node *temp = (struct tree_node*)malloc(sizeof(tree_node));
    temp->data = label;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tree_node *buscar_nodo_tree(struct tree_node *Tree,char label)
{
    if( Tree !=NULL)
    {
        if(Tree->data == label)
        {
            return Tree;
        }
        else
        {
            struct tree_node *Left = buscar_nodo_tree(Tree->left,label);
            struct tree_node *Right = buscar_nodo_tree(Tree->right,label);
            if(Left!= NULL)
            {
                return Left;
            }
            else if(Right!=NULL)
            {
                return Right;
            }
        }
    }
    return NULL;
}

struct list_node *crear_nodo_list(char data) //lista
{
    struct list_node *temp = (struct list_node*)malloc(sizeof(list_node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct list_node *agrega_nodo_list(struct list_node* L,char data) //lista
{
    if(L != NULL)
    {
        struct list_node* temp = L;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = nuevo_nodo(data);
    }
    else
    {
        L = nuevo_nodo(data);
    }
    return L;
    
}

struct tree_node* MaxST(int graph[5][5], int size)
{   
    /*
    Params:
    - graph: Matriz de adyacencia
    Returns:
    Puntero p que apunta al inicio del arbol MaxST
    */
   if(size==0)
   {
       return NULL;
   }
   else if(size<0)
   {
       struct tree_node *root=crear_nodo_tree(labels[0]);
       int A[5];
       A[0]=0;//la distancia de A a A es 0
       int large=1; //Ya tengo un nodo
       for(int i=0 ;i<size;i++)
       {
           graph[i][0]=-1;
       }
       while(large<size)
       {
           int m=-1,f=-1,t=-1;
           for(int i=0;i<large;i++)
           {
               for(int j=0;j<size;j++)
               {
                   if(m<graph[A[i]][j])
                   {
                       m=graph[A[i]][j];
                       f=A[i];
                       t=j;
                   }
               }
           }
           A[large]=t;
           if (t!=-1)
           {
               for (int i =0;i<size;i++)
               {
                   graph[i][t]=-1;
               }
           }
           struct tree_node* temp =buscar_nodo_tree(root,labels[f]);
           if(temp->left == NULL)
           {
               temp->left = crear_nodo_tree(labels[t]);
           }
           else
           {
               temp->right = crear_nodo_tree(labels[t]);
           }
           large++;           
        }
    return root;
   }
}

struct list_node* Amigos_Sugeridos(int graph[5][5],int size, struct tree_node *tree, char name)
{   
    /*
    Params:
    - graph: Matriz de adyacencia
    - tree: Puntero al inicio del arbol
    - name: Caracter
    Returns:
    Puntero p que apunta al inicio de la lista con los amigos sugeridos
    */

   /*
   Tengo que revisar el nodo del arbol que corresponda a la variable "name" y ver cuales son sus hijos y sus padres,
   luego ver los nodos padre e hijos de el y ver si son amigos de "name" para agregarlos en la lista.
    */
   int case_null=1;
    for(int i=0;i<size;i++)
    {
        if(name != labels[i])
        {
            case_null++;
        }
    }

    //identificar el indice de "name" en "labels"
    int indice_name;
    int indice_friend;
    for(int i=0;i<size;i++) 
    {
        if(name==labels[i])
        {
            indice_name=i;
        }
    }

    //caso de que el "name" no esté en labels
    if(case_null == size)
    {
        return NULL;
    }
    else //Caso en que el "name" está en labels
    {
        
        struct list_node* lista_amigos=(struct list_node*)malloc(sizeof(list_node)); //Creo la lista de amigos sugeridos
        struct tree_node* temp=buscar_nodo_tree(tree,name);
        struct tree_node* temp1=(struct tree_node*)malloc(sizeof(tree_node));
        if(temp!=tree)
        {
            if(temp ==tree->left)
            {
                temp1=tree;
            }
            else if(temp==tree->right)
            {
                temp1=tree;
            }
        }
        if (temp->left !=NULL)
        {
            if(temp!=tree)
            {
                if(temp ==tree->left)
                {
                    temp1=tree;
                }
            }
            else
            {
                temp1=temp->left;            
            }
            
            temp1=temp->left;
            if(temp1->left !=NULL)
            {
                struct tree_node* Posible_amigo=(struct tree_node*)malloc(sizeof(tree_node));
                Posible_amigo=temp1->left;
                for(int i=0;i<size;i++)
                {
                    if(Posible_amigo->data == labels[i])
                    {
                        indice_friend=i;
                    }
                }
                if(graph[indice_name][indice_friend]!=-1)
                {
                    lista_amigos->data=labels[indice_friend];
                }
            }
            struct tree_node* posible_amigo2=(struct tree_node*)malloc(sizeof(tree_node));
            lista_amigos->next = posible_amigo2;
            if (temp1->right !=NULL)
            {
               posible_amigo2=temp1->right;
                for(int i=0;i<size;i++)
                {
                    if(posible_amigo2->data == labels[i])
                    {
                        indice_friend=i;
                    }
                }
                if(graph[indice_name][indice_friend]!=-1)
                {
                    lista_amigos->data=labels[indice_friend];
                }

            }
        }
        else if(temp->right !=NULL)
        {
           if(temp!=tree)
            {
                if(temp ==tree->right)
                {
                    temp1=tree;
                }
            }
            else
            {
                temp1=temp->right;            
            }
            if(temp1->left !=NULL)
            {
                struct tree_node* Posible_amigo=temp1->left;
                for(int i=0;i<size;i++)
                {
                    if(Posible_amigo->data == labels[i])
                    {
                        indice_friend=i;
                    }
                }
                if(graph[indice_name][indice_friend]!=-1)
                {
                    lista_amigos->data=labels[indice_friend];
                }
            }
            struct tree_node* posible_amigo2=(struct tree_node*)malloc(sizeof(tree_node));
            lista_amigos->next = posible_amigo2;
            if (temp1->right !=NULL)
            {
                posible_amigo2=temp1->right;
                for(int i=0;i<size;i++)
                {
                    if(posible_amigo2->data == labels[i])
                    {
                        indice_friend=i;
                    }
                }
                if(graph[indice_name][indice_friend]!=-1)
                {
                    lista_amigos->data=labels[indice_friend];
                }
            }
        }
        return lista_amigos;
    }
}