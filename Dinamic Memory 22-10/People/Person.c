#include <stdlib.h>
#include "Person.h"



static void initialize(Person* this, int age, int something);
/** \brief  Reseva espacio en meomoria para una nueva persona y la inicializa
 *
 * \param int age Edad de la persona
 * \param int something Otros datos*
 * \return Person* Retorna un puntero a la persona o NULL en caso de error
 *
 */
Person* person_new (int age, int something)
{
    Person* this = malloc(sizeof(Person));  //reserva memoria dinamicamente para una persona
    if(this != NULL)                        //si la memoria reservada es distinto a nulo
        initialize(this,age,something);     //llama a esta funcion
    return this;
}
/** \brief  Inicializa a una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \param int something Otros datos
 * \return void
 *
 */
static void initialize(Person* this, int age, int something)
{
    this->age = age;       //inicializa con numeros
    this->something = something;    //inicializa con numeros
}
/** \brief  Setea la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \param int age Edad de la persona
 * \return void
 *
 */
void person_setAge(Person* this, int age)
{
    if(age > 0)
        this->age = age;        //coloca la edad valida
        //robusto: se refiere a que los errores son muy minimos, achicar el margen de
        //error
}
/** \brief Obtiene la edad de una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return int age Edad de la persona*
 *
 */
int person_getAge(Person* this)
{
    return this->age;       //obtiene la edad en la posicion que le hemos pasado por
                            //parametro
}
/** \brief Libera el espacio ocupado por una persona recibida como parametro
 * \param Person* this Puntero a la persona
 * \return void
 *
 */
void person_free(Person * this) {
    // Do any other freeing required here.
    free(this);
}
