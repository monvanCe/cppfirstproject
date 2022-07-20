#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdlib> 
#include <ctime>
#include<string>
#include<vector>
using namespace std;
vector<string> names;
vector<float> puanlar;
ofstream file;
ifstream Okuma("Puan.txt", ios::in);
int sayac1=0;
int main (){
    string satir = "";
    float temp;
    string tempName;
    file.open("Puan.txt", ios::app);
    cout << "amaciniz size verilen 10 hak icerisinde, olusturulan rastgele 4 haneli sayiyi tahmin etmektir." << endl;
    cout << "eger rakam dogru hanesi yanlis ise - rakam ve hanesi dogru ise + ipucu verilir. " << endl;
int a,b,c,d;
    srand(time(NULL));
    a = rand() % 10;
        while ( a==0){
        a = rand() % 10;
        }
    b = rand() % 10;
    c = rand() % 10;
    d = rand() % 10;
        while ( a==b || a==c || a==d || b==c || b==d || c==d){
            b = rand() % 10;
            c = rand() % 10;
            d = rand() % 10;
        }
//    cout << a << b << c << d << endl;
int quadno[4] = {a,b,c,d};
float hak = 1;
int quadguess;
int e,f,g,h;
float plus2=0;
float minus2=0;
float puan=0;
char name[25];
cout << "isminizi yaziniz: ";
cin >> name;
    while ( hak<=10){
    cout << "lutfen rakamlari farkli 4 haneli bir sayi giriniz:";
    cin >> quadguess;
e = quadguess / 1000;
f = (quadguess - (e*1000)) / 100;
g = (quadguess - (f*100) - (e*1000)) / 10;
h = (quadguess - (e*1000) - (f*100) - (g*10));
    if ( (quadguess < 1000 || quadguess > 9999) || (e==f || e==g || e==h || f==g || f==h || g==h)){
        cout << "(!)lutfen rakamlari farkli 4 haneli bir sayi giriniz:";
        cin >> quadguess;
        cout << 10-hak << endl;
    }
//    cout << e << f << g << h << endl;
int plus = 0;
int minus = 0;
    if ( ((a*1000) + (b*100) + (c*10) + d) != ((e*1000) + (f*100) + (g*10) + h) ){
            if ( a==e ){
                plus++;
                plus2++;
            }
            if ( b==f ){
                plus++;
                plus2++;
            }
            if ( c==g ){
                plus++;
                plus2++;
            }
            if ( d==h ){
                plus++;
                plus2++;
            }
            for (int i=1; i<4; i++){
                if( e==quadno[i]){
                    minus++;
                    minus2++;
                }
            }
            if ( f==a ){
                minus++;
                minus2++;
            }
            for (int i=2; i<4; i++){
                if( f==quadno[i]){
                    minus++;
                    minus2++;
                }
            }  
            if ( g==d){
                minus++;
                minus2++;
            }  
            for (int i=0; i<2; i++){
                if( g==quadno[i]){
                    minus++;
                    minus2++;
                }
            }
            for (int i=0; i<3; i++){
                if( h==quadno[i]){
                    minus++;
                    minus2++;
                }
            }
            cout << hak <<endl;
            hak++;  
        cout << plus << " " << "-" << minus << endl; 
//        cout << plus2 << " " << "-" << minus2 << endl;   
        }
    else {
    cout << "dogru bildin" << endl;
        cout << "kalan hak: " << 10-hak << endl;
        plus+=4;
        plus2+=4;
        cout << plus << " " << "-" << minus << endl;
//        cout << plus2 << " " << "-" << minus2 << endl; 
    puan = 10*plus2 + 5*minus2 + 1000/hak - (plus2*minus2)/(plus2+minus2);
    cout << "puaniniz: " << puan << endl;
    file << name << ", puanin=" << puan << endl;
                file.close();
    if (Okuma.is_open())
                {
                    while (getline(Okuma, satir))
                    {
                        names.push_back(satir.substr(0, satir.find(",")));
                        puanlar.push_back(stof(satir.substr(satir.find("=") + 1)));
    //                    cout << satir.substr(0, satir.find(",")) << endl;
    //                   cout << stof(satir.substr(satir.find("=") + 1)) << endl;
                    }
                    file.close();
 //                   cout << puanlar.size() << endl;
                    for (int k = 0; k < puanlar.size() - 1; k++)
                    {
                        for (int j = 0; j < puanlar.size() - 1; j++) {
                            if (puanlar[j] < puanlar[j + 1]) {
                                temp = puanlar[j];
                                tempName = names[j];
                                names[j] = names[j + 1];
                                names[j + 1] = tempName;
                                puanlar[j] = puanlar[j + 1];
                                puanlar[j + 1] = temp;
                            }
                        }
                    }
                // Okuma.close();
                ofstream Yazma("Puan.txt");
                sayac1 = puanlar.size();
                if (sayac1 > 10)
                {
                    sayac1 = 10;
                }
//                cout << sayac1 << endl;
                for (int i = 0; i < sayac1; i++)
                {
                    Yazma << names[i] << ", puanin=" << puanlar[i] << "\n";
                }
                }
                break;        
    }
}
if ( hak == 11){
cout << "bilemediniz"<< endl;
cout << "sayi bu idi: " << a << b << c << d;
}
system("pause");
}