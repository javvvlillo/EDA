#include <stdio.h>
#include <stdlib.h>
#include "Prueba4.h"

char labels[5] = {'A', 'B','C','D','E'};

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

   struct L{
       int valor;
       char actual;
       char unido;
    };

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(graph[i][j]!=-1 || i == j)
            {
                for(int k=0;k<size*size;k++)
                {
                    struct L *list=(struct L*)malloc(sizeof(struct L));
                    list[k].actual=labels[i];
                    list[k].unido=labels[j];
                    list[k].valor=graph[i][j];
                }
            }
        }
    }

    struct tree_node *root =NULL;

    struct tree_node *temp=(struct tree_node*)malloc(sizeof(tree_node));
    temp->data=labels[0];
    temp->left=NULL;
    temp->right=NULL;
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