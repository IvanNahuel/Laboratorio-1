#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;

    if (this!=NULL && nodeIndex>=0 && nodeIndex < ll_len(this))
    {
        pNode = this->pFirstNode;
        for (i=0; i<ll_len(this); i++)
        {
            if (i==nodeIndex)
            {
                break;
            }
            else
            {
                pNode = pNode->pNextNode;
            }
        }
    }
    return pNode;
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevoNodo = (Node*)malloc(sizeof(Node));    //creame un espacio de memoria para NODO
            if(nuevoNodo != NULL)                       //si el espacio de memoria (NUEVO) ES NO NULO
            {
                nuevoNodo->pElement = pElement;         //el *nuevo nodo, campo pElement es igual al param
                nuevoNodo->pNextNode = NULL;            //*nuevo nodo siguiente nodo, es NULO

                if(nodeIndex == 0)                              //si el indice PARAM ES CERO
                {
                    nuevoNodo->pNextNode = this->pFirstNode;    //*nuevo nodo el siguiente nodo, es el primero
                    this->pFirstNode = nuevoNodo;               //de THIS el primer nodo es la estructura *nuevo nodo
                }
                else                                            //si no es 0 el indice
                {
                    prev = this->pFirstNode;                    //*prev es igual a this->primerNodo (PRIMER NODO)
                    next = prev->pNextNode;                     //*next es igual a *prev del siguiente nodo

                    while( nodeIndex > 1)                       //mientras nodo index sea mayor a 1
                    {
                        prev  = next;                           //*prev es igual al siguiente
                        next  = prev->pNextNode;                //*next es igual a prev->nextNode
                        nodeIndex--;                            //index --
                    }
                    prev->pNextNode = nuevoNodo;                //*prev->pNextNode es igual a nuevo nodo
                    nuevoNodo->pNextNode = next;                //*nuevo nodo->nextNode = next
                }
                this->size++;                                   //incremento el size
                returnAux = 0;
            }
        }
    }
    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        addNode(this,this->size,pElement);
        returnAux =0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    int i;
    if (this!=NULL && index >=0 && index < ll_len(this))
    {
        pNode = getNode(this, index);
        if (pNode != NULL)
        {
            returnAux = pNode->pElement;
        }
    }
    return returnAux;
}
/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    //printf("\n1 --- INDEX(%d) --- LEN (%d) -- THIS(%x)", index, ll_len(this), this);
    int returnAux = -1;
    Node*pAuxiliar;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        pAuxiliar = getNode(this,index);
        if (pAuxiliar!=NULL)
        {
            pAuxiliar->pElement = pElement;
            returnAux = 0;
        }

    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int i;
    Node*pNode;
    Node*pNodeDelete;
    Node*PFirst;
    Node*PSiguiente;
    if (this!=NULL && index >=0 && index <ll_len(this))
    {
        PFirst = this->pFirstNode;
        PSiguiente = PFirst->pNextNode;
        pNodeDelete = getNode(this,index);
        if (index==0)
        {
            //si quiero eliminar el cero debo decirle a this que el primer nodo es el siguiente
            this->pFirstNode =PSiguiente;
        }
        //si quiero eliminar el ultimo elemento debo decirle que el anterior apunte a null
        else if (index==ll_len(this)-1)
        {
            pNode = getNode(this,index-1);
            pNode->pNextNode = NULL;
        }
        else
        {
            //si quiero eliminar uno del medio debo decir que el anterior apunte al que le
            //sigue del que quiero eliminar
            pNode = getNode(this,index-1);
            Node*pNodeAux = getNode(this,index+1);
            pNode->pNextNode =pNodeAux;
        }
        returnAux = 0;
        this->size--;
        free(pNodeDelete);
    }
    //tengo que obtener el elemento anterior al indice y el siguiente
    //y setear el pNextNode
    //osea conectar (el index-1) y decirle que el siguiente es (el index +1)
    return returnAux;
}
/** \brief Elimina todos los elementos de la lista
*
* \param this LinkedList* Puntero a la lista
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                            ( 0) Si funciono correctamente
*
*/
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node *pNode;

    int i;

    if (this!=NULL)
    {
        pNode = this->pFirstNode;

        for (i=0; i<ll_len(this); i++)
        {
            //aca iriamos llamando a remove hasta que se termine
            ll_remove(this,i);
            i++;
            returnAux =0;
        }
    }
    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux =0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    //recorrer el array y comparar elementos si son iguales retornar el indice
    if (this!=NULL)
    {
        Node*pNode = this->pFirstNode;

        for (i=0; i<ll_len(this); i++)
        {
            if (pNode->pElement == pElement)
            {
                returnAux = i;
            }
            else
            {
                pNode = pNode->pNextNode;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if (ll_len(this)==0 && this!=NULL)
    {
        returnAux = 1;
    }
    else if (this!=NULL &&ll_len(this)>0)
    {
        returnAux =0;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node*NuevoNodo;
    Node*PrevAux;
    Node*NextAux;

    NuevoNodo = (Node*)malloc(sizeof(Node));

    if (this!=NULL && index > 0 && index <ll_len(this))
    {
        addNode(this,index,pElement);
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node*pNode;

    if (this!=NULL && index>=0 && index<ll_len(this))
    {
        pNode = getNode(this,index);
        returnAux = pNode->pElement;
        ll_remove(this,index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;


    if (this!=NULL)
    {
        returnAux = ll_indexOf(this,pElement);
        if (returnAux ==-1)
        {
            returnAux =0;
        }
        else
        {
            returnAux =1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;
    int i;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i < ll_len(this2); i++)
        {
            pElement = ll_get(this2,i);
            if(ll_contains(this,pElement) == 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* pList = NULL;
    void* pElement = NULL;
    int i;
    if(this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
        pList = ll_newLinkedList();
        for(i = from ; i < to; i++)
        {
            pElement = ll_get(this, i);
            ll_add(pList, pElement); // Enlaza
        }
    }
    return pList;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 *                      ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    void* nodeUno = NULL;
    void* nodeDos = NULL;
    void* temp = NULL;
    int i,j;
    int flag = 0;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        do
        {
            for(i=0 ; i < (this->size-1) ; i++)
            {
                nodeUno = ll_get(this, i);
                for(j = i+1 ; j < (this->size) ; j++)
                {
                    nodeDos = ll_get(this, j);
                    if(order == 0)
                    {
                        if(pFunc(nodeUno, nodeDos) < 0)
                        {
                            temp = nodeDos;
                            nodeDos = nodeUno;
                            nodeUno = temp;
                        }
                    }
                    if(order == 1)
                    {
                        if(pFunc(nodeUno, nodeDos) > 0)
                        {
                            temp = nodeUno;
                            nodeUno = nodeDos;
                            nodeDos = temp;
                        }
                    }
                    ll_set(this, i, nodeUno);
                    ll_set(this, j, nodeDos);
                    flag = 1;
                }
            }
            returnAux = 0;
        }
        while(flag);
    }
    return returnAux;
}
/*
int al_map (LinkedList*this,int (*pfunc)(void*str),int indice){
	void*AuxThing = ll_get (this,indice);
	if (this!=NULL && AuxThing !=NULL){
		pfunc (AuxThing,this);
		retorno =0;
	}
return retorno;
}*/

int al_map (LinkedList*this, void (*pfunc)(void*str,int indice))
{
    //
    void*AuxThing;
    int i;
    int cant;
    cant = ll_len(this);

    if (this!=NULL)
    {
        //aca la iteracion
            AuxThing = ll_get(this,indice);
            pfunc (AuxThing);

    }
    return 0;
}





