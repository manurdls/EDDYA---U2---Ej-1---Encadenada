#include <iostream>
#include <stdlib.h>
using namespace std;

class celda{
	private:
		int item;
		celda *next;
	public:
		int getItem(void){
			return (item);
		}
		
		void setItem(int xitem){
			item = xitem;
		}
		
		void setNext(celda *xtop){
			next = xtop;
		}
		
		celda* getNext(void){
			return (next);
		}
	
};

class Pila{
	private:
		celda *top;
		int size;
	public:
		Pila(celda* xtop=NULL,int xsize=0):top(xtop),size(xsize){ }
		int getSize();
		bool getEmpty(void);
		int getTop();
		int pushTop(int x);
		int supTop();
		void toShow();
		~Pila();
};

int Pila::getSize(){
	return (size);
}

bool Pila::getEmpty(void){
	return (size==0);
}

int Pila::getTop(){
	return(top->getItem());
}

int Pila::pushTop(int x){
	celda *ps1;
	ps1=new(celda);
	ps1->setItem(x);
	ps1->setNext(top);
	top=ps1;
	size++;
	return (ps1->getItem());
}


		
		
int Pila::supTop(void){
	celda *aux;
	int x;
	if (getEmpty()){
		puts("Pila vacia");
		return(0);
	}
	else{
		aux=top;
		x=top->getItem();
		top=top->getNext();
		size--;
		return(x);
	}
}
		
void Pila::toShow(void){
	celda *aux=top;
	bool flag=1;
	
	if (getEmpty()){
		while (aux != NULL && flag){
			printf("%d\n", aux->getItem());
			if (aux->getNext() == NULL){
				flag = 0;
			}
			else{
				aux=aux->getNext();
			}
		}
	}
	else{
		puts("La pila esta vacia");
	}
}

Pila::~Pila(){
	celda *aux=top;
	bool flag=1;
	
	while (top != NULL && flag){
		if (top->getNext() == NULL){
			flag = 0;
		}
		else{
			aux=top->getNext();
			delete top;
			top=aux;
		}
	}
}

void test(Pila &unaPila){
	unaPila.pushTop(33);
	unaPila.pushTop(22);
	unaPila.pushTop(1);
	unaPila.pushTop(56);
	if (unaPila.getEmpty())
		printf("La lista esta vacia.");
	else
		cout<<"Valor del tope: "<<unaPila.getTop()<<"\nCantidad actual de elementos: "<<unaPila.getSize()<<endl;
		
	printf("--------------------------------\n");
	unaPila.supTop();
	unaPila.supTop();
	if (unaPila.getEmpty())
		printf("La lista esta vacia.");
	else
		cout<<"Valor del tope: "<<unaPila.getTop()<<"\nCantidad actual de elementos: "<<unaPila.getSize()<<endl;
		
	printf("--------------------------------\n");
	unaPila.supTop();
	unaPila.supTop();
	if (unaPila.getEmpty())
		printf("La pila esta vacia.");
	else
		cout<<"Valor del tope: "<<unaPila.getTop()<<"\nCantidad actual de elementos: "<<unaPila.getSize()<<endl;
}

int main(){
	Pila unaPila;
	test(unaPila);
}
