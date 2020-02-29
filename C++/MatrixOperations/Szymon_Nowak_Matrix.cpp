#include<iostream>
#include<string>
#include<fstream>
#include <ostream>
#include <istream>

const int m=3,n=2;
 using namespace std;
 class Matrix{
 	private:
 		int n,m;
 		int **element;
 		string name;
 	
 	public:
 		Matrix(void);
 		Matrix(int m,int n,string name);
 		friend Matrix add(Matrix m,Matrix n,Matrix o);
 		friend Matrix iloczyn(Matrix m,Matrix p,int mnoznik);
 		friend Matrix iloczynMacierzy(Matrix m,Matrix n,Matrix r);
 		friend Matrix trans(Matrix m,Matrix z);
 		friend ostream& operator <<(ostream &wyj,Matrix x);
 		friend istream& operator >>(istream &wej,Matrix x);
 		friend Matrix operator+(Matrix m,Matrix n);
 		friend Matrix operator*(Matrix m,int mnoznik);
 		friend Matrix operator*(Matrix m,Matrix n);
 		
 	void getMatrix(){
 		for(int i=0;i<m;i++){
 			for(int j=0;j<n;j++)
 				cout<<element[i][j]<<" ";
 			cout<<endl;
		 }
	 };
 	void setMatrix(){
 		for(int i=0;i<m;i++)
 			for(int j=0;j<n;j++)
 				cin>>element[i][j];
	 };
	 	 
/*	 void wyznacznik2(void){
	 	int wyznacznik;
	 	wyznacznik=element[0][0]*element[1][1]-element[0][1]*element[1][0];
	 	cout<<"Wyznacznik jest rowny "<<wyznacznik;
	 }
	 
	 */	 
	 void wyznacznik2(void){
    	int wyznacznik;
       	wyznacznik = element[0][0] * element[1][1] - element[1][0] * element[0][1];
        	cout<<"Wyznacznik równy jest "<<wyznacznik<<endl;
	}
	  void wyznacznik1(void){
    	int wyznacznik;
       	wyznacznik = element[0][0];
        	cout<<"Wyznacznik równy jest "<<wyznacznik<<endl;
	}
	  void wyznacznik3(void){
    	int wyznacznik;
       	wyznacznik = element[0][0] * element[1][1] * element[2][2] + element[0][1] * element[1][2] * element[2][0] + element[0][2] * element[1][0] * element[2][1] - ( element[0][2] * element[1][1] * element[2][0] + element[0][0] * element[1][2] * element[2][1] + element[0][1] * element[1][0] * element[2][2]);
        	cout<<"Wyznacznik równy jest "<<wyznacznik<<endl;
	}
	 	 
	 
 };
 int main(){
 //	Matrix T1(2,2,"T1");
// 	Matrix m(4,3,"nazwa");
 	double wymiar_x,wymiar_y;
 	cout<<"Podaj wymiary pierwszej Macierzy"<<endl;
 	cin>>wymiar_x;
 	cin>>wymiar_y;
 	
 	Matrix MacierzA(wymiar_x,wymiar_y,"nazwa");
 //	MacierzA.getMatrix();
	cout<<MacierzA; 
 //	MacierzA.setMatrix();
 	cin>>MacierzA;
 //	MacierzA.getMatrix();
 	cout<<MacierzA;	
 	
 	
 	double wymiar_xx,wymiar_yy;
 	cout<<"Podaj wymiary drugiej Macierzy"<<endl;
 	cin>>wymiar_xx;
 	cin>>wymiar_yy;
 	Matrix MacierzB(wymiar_xx,wymiar_yy,"nazwa2");
 	MacierzB.getMatrix();
 	MacierzB.setMatrix();
 	
 	//MacierzB.getMatrix();
 	cout<<MacierzB;
 	
 if(wymiar_x!=wymiar_xx && wymiar_y!=wymiar_yy){
	 
		cout<<"Nie mozna wykonac dodawania ";
 }
 	else if(wymiar_x==wymiar_xx && wymiar_y==wymiar_yy){
 //	add(MacierzA,MacierzB,MacierzC);
 //	MacierzC.getMatrix();
 	
 	//	Matrix MacierzC(wymiar_x,wymiar_y,"Suma");
 	Matrix MacierzC=MacierzA+MacierzB;
 cout<<MacierzC<<endl;//.getMatrix();

 }
 	
 	
 	
 	
 	
 	
 		if(wymiar_x==wymiar_y){   
    	if(wymiar_x==2){
    	MacierzA.wyznacznik2();
    }
    	else if(wymiar_x==1){
    		MacierzA.wyznacznik1();
		}
		else if(wymiar_x==3){
    		MacierzA.wyznacznik3();
		}
}
	else{
		cout<<"Macierz nie jest kwadratowa lub jest wieksza niz 3x3"<<endl;
	}	
	
 	
 int mnoznik;
 cout<<"Podaj liczbe przez jaka chcesz pomnozyc Macierz pierwsza"<<endl;
 cin>>mnoznik;
 //iloczyn(MacierzA,MacierzD,mnoznik);
 cout<<"Mnozenie pierwszej Macierzy"<<endl;
 Matrix MacierzD=MacierzA*mnoznik;
 cout<<MacierzD;//<<endl;//.getMatrix();
 
 if(wymiar_x!=wymiar_yy){
 	cout<<"Mnozenie dwoch Macierzy nie jest mozliwe"<<endl;
 }
 else if(wymiar_x==wymiar_yy){
 	cout<<"Mnozenie dwoch Macierzy"<<endl;
 	//Matrix MacierzE(wymiar_xx,wymiar_y,"Iloczyn Macierzy");
 //	MacierzE.getMatrix();
 Matrix MacierzE=MacierzA*MacierzB;
 //	iloczynMacierzy(MacierzA,MacierzB,MacierzE);
 	MacierzE.getMatrix();
 }

 	cout<<"Transponowanie Macierzy"<<endl;
 	Matrix MacierzF(wymiar_y,wymiar_x,"Tranponowana");
 	//MacierzF.getMatrix();
 	trans(MacierzA,MacierzF);
 	MacierzF.getMatrix();
 	
 	
 	
 	
 }
 Matrix trans(Matrix MacierzA,Matrix MacierzF){
 	for(int i=0;i<MacierzA.m;i++){
 		for(int j=0;j<MacierzA.n;j++){
 			MacierzF.element[j][i]=MacierzA.element[i][j];
		 }
	 }
	 return MacierzF;
 }
 
 Matrix iloczynMacierzy(Matrix MacierzA,Matrix MacierzB,Matrix MacierzE){
 	cout<<"Mnozenie dwoch Macierzy"<<endl;
 	for(int i=0;i<MacierzE.m;i++){
	for(int j=0;j<MacierzE.n;j++){
		for(int k=0;k<MacierzA.n;k++){
		
MacierzE.element[i][j]+=MacierzA.element[i][k]*MacierzB.element[k][j];
}
}
}
return MacierzE;
 }
 
 
 
 Matrix iloczyn(Matrix MacierzA,Matrix MacierzD,int mnoznik){
 	cout<<"Mnozenie pierwszej Macierzy"<<endl;
 	for(int i=0;i<MacierzA.m;i++){
	for(int j=0;j<MacierzA.n;j++){
	MacierzD.element[i][j]=MacierzA.element[i][j]*mnoznik;
	}
}
 	return MacierzD;
 }
 
 Matrix add(Matrix MacierzA,Matrix MacierzB,Matrix MacierzC){
// 	cout<<"cos sie dzieje"<<endl; 
for(int i=0;i<MacierzA.n;i++){
	for(int j=0;j<MacierzA.m;j++){
		MacierzC.element[i][j]=MacierzA.element[i][j]+MacierzB.element[i][j];
	}
}
	 return MacierzC;
 }
 
Matrix::Matrix(int a,int b,string nazwa){
 	n=a;
 	m=b;
 	name=nazwa;
 	element= new int*[b];
 	for(int i=0;i<b;i++){
 		element[i]=new int[a];	
	 }
 	for(int i=0;i<b;i++)
 		for(int j=0;j<a;j++)
 			element[i][j]=0;
 }
 
 
 ostream& operator <<(ostream &wyj,Matrix x){
 	for(int i=0;i<x.m;i++){
 			for(int j=0;j<x.n;j++)
 				wyj<<x.element[i][j]<<" ";
 			wyj<<endl;
		 }
		 return wyj;
 }
 istream& operator >>(istream &wej,Matrix x){
 	for(int i=0;i<x.m;i++)
 			for(int j=0;j<x.n;j++)
 				cin>>x.element[i][j];
 	return wej;
 }
 
 Matrix operator+(Matrix m,Matrix n){
 	Matrix MacierzC(m.m,m.n,"dod");
 	for(int i=0;i<m.n;i++){
	for(int j=0;j<m.m;j++){
		MacierzC.element[i][j]=m.element[i][j]+n.element[i][j];
	}
}
	 return MacierzC;
 }
 
 Matrix operator*(Matrix X,int mnoznik){
 	Matrix MacierzD(X.m,X.n,"Iloczyn");
 //	MacierzD.getMatrix();
 //	
 	for(int i=0;i<X.m;i++)
		for(int j=0;j<X.n;j++)
			MacierzD.element[i][j]=X.element[i][j]*mnoznik;
	

 	return MacierzD;
 
 }
 Matrix operator*(Matrix X,Matrix Y){
 	Matrix MacierzE(Y.n,X.m,"Iloczyn Macierzy");
 	cout<<MacierzE;
 	for(int i=0;i<MacierzE.m;i++){
	for(int j=0;j<MacierzE.n;j++){
		for(int k=0;k<X.n;k++){
		
MacierzE.element[i][j]+=X.element[i][k]*Y.element[k][j];
}
}
}
return MacierzE;
 
 
 
 
 }
 
Matrix::Matrix(void){
};
