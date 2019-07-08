#include <stdio.h>
#include <stdlib.h>
#include "Prueba4.h"

char labels[5] = {'A', 'B','C','D','E'};

struct tree_node *crear_nodo_tree(char data) //arbol
{
    struct tree_node *temp = (struct tree_node*)malloc(sizeof(tree_node));
    temp->data = data;
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


    return NULL;
}