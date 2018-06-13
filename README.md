# TOMAPAN-GAME

  Jocul Tomapan este unul de cultura generala in care cei doi jucatori trebuie sa introduca date de la tastatura care sa indeplineasca 
anumite conditii. Aceste conditii sunt : 
          1 in executabil va aparea o litera, aceasta litera este afisata de program si este una random . Pentru a obtine aceasta litera 
           am folosit un arbore simblu care genereaza dupa un algoritm o litera (algoritmul de mai jos )
           
           
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

    2 Cea de-a doua conditie este ca jucatorii sa introduca nume de : tari, orase , munti,ape , plante , animale si nume care incep cu 
    litera respectiva.Pentru a putea valida datele introduse de la tastatura am creat fisiere cu : nume , plante , ape , etc iar programul 
    de ferificare da cauta in fiecare fisier txt daca corespunde cu datele introduse .
    
    
        Castigatorul este cel care are punctajul cel mai mare. Pentru un raspuns corect 10 puncte , pentru un raspuns corect dar identic
      cu oponentul 5 puncte pentru ambi jucatori.
      Pentru reinceperea jocului, cei doi jucatori vor apasa tasta 1 iar pentru iesirea din joc tasta 0.
