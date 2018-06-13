#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Nod{
    Nod * urm;
    int valoare;
};
void verificarefisier(const char *filename)
{
    int loop=0;
    string line;
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        cout<<"\nFisierul "<<filename<<" exista";
        myfile.close();
    }
    else
    {
        cout << "\nNu se poate deschide fisierul: "<<filename;
    }

}

bool cautare(string value, const char *filename)
{
    int loop=0;
    string line;
    ifstream myfile (filename);
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            if(line==value)
            {
                return true;
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Nu se poate deschide fisierul: "<<filename;
    }
}

struct NodArbore {
    int value;
    NodArbore * left, * right;
};

void buildArbore(NodArbore * p, int nivel, int &value, const int alphCount) {
    if (nivel == 5) {
        p->value = value % alphCount;
        value++;
        p->left = p->right = nullptr;
    }
    else
    {
        p->left = new NodArbore;
        buildArbore(p->left, nivel+1, value, alphCount);
        p->right = new NodArbore;
        buildArbore(p->right, nivel+1, value, alphCount);
    }
}

char getRandChar(NodArbore * rad)
{
    NodArbore * p = rad;
    for (int i = 0; i < 5; i++)
    {
        int r = rand() % 2;
        if (r == 0)
            p = p->left;
        else
            p = p->right;
    }
    return 'A' + p->value;
}

string literarandom()
{
    NodArbore * rad = new NodArbore;
    rad->left = rad->right = nullptr;
    int value = 0;
    buildArbore(rad, 0, value, 26);

    //for (int i = 0; i < 100; i++)
        //cout<<getRandChar(rad);

    /*char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N',
                          'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                          'V', 'W', 'X', 'Y', 'Z'
                        };
*/
    string res = "";
    for (int i = 0; i < 1; i++)
        //res = res + alphabet[rand() % 26];
        res = res + getRandChar(rad);

    return res;

}
bool corect(string mainStr, string toMatch)
{
    // Convert mainStr to lower case
    transform(mainStr.begin(), mainStr.end(), mainStr.begin(), ::tolower);
    // Convert toMatch to lower case
    transform(toMatch.begin(), toMatch.end(), toMatch.begin(), ::tolower);

    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}
int main ()
{
    cout<<"********************************************************************************";
    cout<<"**************************Tari Capitale Orase Animale***************************";
    cout<<"********************************************************************************";
    int selectia;
    string tara[2];
    string capitala[2];
    string oras[2];
    string animal[2];
    string apa[2];
    string nume[2];
    string munte[2];
    string plante[2];
    Nod* prim=new Nod;
    Nod* q=new Nod;
    q->urm=nullptr;
    prim->urm=q;
    cout<<"\nVerificare:\n";
    verificarefisier("tari.txt");//citire din fisier tari
    verificarefisier("capitale.txt");//citire din fisier capitale
    verificarefisier("orase.txt");//citire orase
    verificarefisier("animale.txt");//citire animale
    verificarefisier("ape.txt");//citire ape
    verificarefisier("nume.txt");//citire nume
    verificarefisier("munte.txt");//citire munti
    verificarefisier("plante.txt");//citire plante
    //afisare();
    //meniu
    while(1)
    {
        cout<<"\nIntroduceti numarul corespunzator pentru optiunea dorita:\n";
        cout<<"1:start joc\n";
        cout<<"0:Exit\n";
        cin>>selectia;
        if(selectia==0)
        {
            exit(1);
        }

        switch(selectia)
        {
        case 1:
        {

            //scor[0]=0;
            //scor[1]=0;
            prim->valoare=0;
            q=prim->urm;
            q->valoare=0;
            //citire date primul participant;
            string primalitera=literarandom();
            cout<<"\n********************************************************************************";
            cout<<"\n**************************Primul jucator****************************************";
            cout<<"\n********************************************************************************";
            cout<<"\nLitera de inceput este:"<<primalitera;
            cout<<"\nintroduceti tara:";
            cin>>tara[0];
            cout<<"\nintroduceti Capitala:";
            cin>>capitala[0];
            cout<<"\nintroduceti oras:";
            cin>>oras[0];
            cout<<"\nintroduceti animal:";
            cin>>animal[0];
            cout<<"\nintroduceti ape:";
            cin>>apa[0];
            cout<<"\nintroduceti nume:";
            cin>>nume[0];
            cout<<"\nintroduceti munti:";
            cin>>munte[0];
            cout<<"\nintroduceti plante:";
            cin>>plante[0];
            cout<<"\n********************************************************************************";
            cout<<"\n**************************al doilea jucator*************************************";
            cout<<"\n********************************************************************************";
            cout<<"\nLitera de inceput este:"<<primalitera;
            cout<<"\nintroduceti tara:";
            cin>>tara[1];
            cout<<"\nintroduceti Capitala:";
            cin>>capitala[1];
            cout<<"\nintroduceti oras:";
            cin>>oras[1];
            cout<<"\nintroduceti animal:";
            cin>>animal[1];
            cout<<"\nintroduceti ape:";
            cin>>apa[1];
            cout<<"\nintroduceti nume:";
            cin>>nume[1];
            cout<<"\nintroduceti munti:";
            cin>>munte[1];
            cout<<"\nintroduceti plante:";
            cin>>plante[1];

            //validare date player 1 si 2
            if(corect(tara[0],primalitera)||corect(tara[1],primalitera))
            {
                if(tara[0]==tara[1])
                {
                    if(cautare(tara[0],"tari.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(tara[0],"tari.txt")&& corect(tara[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(tara[1],"tari.txt")&&corect(tara[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(capitala[0],primalitera)||corect(capitala[1],primalitera))
            {
                if(capitala[0]==capitala[1])
                {
                    if(cautare(capitala[0],"capitale.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(capitala[0],"capitale.txt")&&corect(capitala[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(capitala[1],"capitale.txt")&&corect(capitala[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(oras[0],primalitera)||corect(oras[1],primalitera))
            {
                if(oras[0]==oras[1])
                {
                    if(cautare(oras[0],"orase.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                }
                else
                {
                    if(cautare(oras[0],"orase.txt")&&corect(oras[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(oras[1],"orase.txt")&&corect(oras[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(animal[0],primalitera)||corect(animal[1],primalitera))
            {
                if(oras[0]==oras[1])
                {
                    if(cautare(oras[0],"animale.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(animal[0],"animale.txt")&&corect(animal[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(animal[1],"animale.txt")&&corect(animal[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(apa[0],primalitera)||corect(apa[1],primalitera))
            {
                if(apa[0]==apa[1])
                {
                    if(cautare(apa[0],"ape.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(apa[0],"ape.txt")&&corect(apa[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(apa[1],"ape.txt")&&corect(apa[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(nume[0],primalitera)||corect(nume[1],primalitera))
            {
                if(nume[0]==nume[1])
                {
                    if(cautare(nume[0],"nume.txt"))
                    {
                         prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(nume[0],"nume.txt")&&corect(nume[0],primalitera))
                    {
                       prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(nume[1],"nume.txt")&&corect(nume[1],primalitera))
                    {
                         Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(plante[0],primalitera)||corect(plante[1],primalitera))
            {
                if(plante[0]==plante[1])
                {
                    if(cautare(plante[0],"plante.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(plante[0],"plante.txt")&&corect(plante[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(plante[1],"plante.txt")&&corect(plante[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(plante[0],primalitera)||corect(plante[1],primalitera))
            {
                if(plante[0]==plante[1])
                {
                    if(cautare(plante[0],"plante.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(plante[0],"plante.txt")&&corect(plante[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(plante[1],"plante.txt")&&corect(plante[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            if(corect(munte[0],primalitera)||corect(munte[1],primalitera))
            {
                if(munte[0]==munte[1])
                {
                    if(cautare(munte[0],"munte.txt"))
                    {
                        prim->valoare=prim->valoare+5;
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+5;
                        //scor[0]=scor[0]+5;
                        //scor[1]=scor[1]+5;
                    }
                }
                else
                {
                    if(cautare(munte[0],"munte.txt")&&corect(munte[0],primalitera))
                    {
                        prim->valoare=prim->valoare+10;
                        //scor[0]=scor[0]+10;
                    }
                    if(cautare(munte[1],"munte.txt")&&corect(munte[1],primalitera))
                    {
                        Nod* doi=prim->urm;
                        doi->valoare=doi->valoare+10;
                        //scor[1]=scor[1]+10;
                    }
                }

            }
            Nod* doi=prim->urm;
            cout<<"\nScorul jucator1 este:"<<prim->valoare;
            cout<<"\nScorul jucator2 este:"<<doi->valoare;
            cout<<"\n";
        }}
        default:
        {
            cout<<"\nselectie incorecta";
        }
        }
    }
    return 0;
}
