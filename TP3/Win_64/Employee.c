int employee_setId(Employee* this,int id){
    if (this!=NULL){
        if(id > 0){
            this->id = id;
        }
    }
}
int employee_getId(Employee* this,int* id){
    if (this!=NULL){
        return this->id;
    }
}

int employee_setNombre(Employee* this,char* nombre){
    if (this!=NULL){                    //si el puntero a persona es distinto a nulo
        strcpy(this->nombre, nombre);   //en la posicion pasada por parametro copiame
    }
}
int employee_getNombre(Employee* this,char* nombre){



}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    if (this!=NULL){
        if(horasTrabajadas > 0){
            this->horasTrabajadas = horasTrabajadas;
        }
    }
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    if (this!=NULL){
        return this->horasTrabajadas;
    }
}
int employee_setSueldo(Employee* this,int sueldo){
    if (this!=NULL){
        if(sueldo > 0){
            this->sueldo = sueldo;
        }
    }
}
int employee_getSueldo(Employee* this,int* sueldo){
    if (this!=NULL){
        return this->sueldo;
    }
}



