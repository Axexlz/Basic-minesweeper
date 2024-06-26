#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int intrebariFolosite[151]; // acum valorile pt intrebariFolosite vor fi 0
void InitMap(int n, int mat[21][21], int mat2[21][21]){
  for(int i = 0; i <= n+1; ++i)
    for(int j = 0; j <= n+1; ++j)
      { mat[i][j] = 0; mat2[i][j] = 0;}
}
void spawnare(int n, int mat[21][21], int &liniestart, int &coloanastart)
{
    srand(time(0)); 
    liniestart = rand() % n + 1;
    coloanastart = rand() % n + 1;
    mat[liniestart][coloanastart] = 5;
}
void afisaretabla(int n, int mat[21][21]){

  cout << "\n\n\n--------------------------------------\n\n";
    for(int u = 1; u <= 4*n + 1; u = u + 1)
      cout << "-";
      cout << "\n";
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
          if(mat[i][j] == 6)
            cout << "| " << "#" << " ";
          else if(mat[i][j]  == 0 || mat[i][j] >= 10)
            cout << "| " << "0" << " ";
          else if(mat[i][j] == 5) cout << "| " << "$" << " ";
          else cout << "| " << "1" << " "; 
        } 
      cout << "| ";
        cout << "\n";
      for(int u = 1; u <= 4*n + 1; u = u + 1)
        cout << "-";
        cout << "\n";
      
    }  
} 
void afisaretablaHide(int n, int mat[21][21], int mat2[21][21]){

  cout << "\n\n\n--------------------------------------\n\n";
  
  for(int u = 1; u <= 4*n + 1; u = u + 1)
    cout << "-";
    cout << "\n";
  for (int i = 1; i <= n; i++) { 
      for (int j = 1; j <= n; j++) { 
        if(mat[i][j] == -1)
          cout << "| " << "*" << " ";
        else if(mat[i][j] == 6)
          cout << "| " << "#" << " ";
        else if(mat[i][j]  == 0)
          cout << "| " << " " << " ";
        else if(mat[i][j] == 5) cout << "| " << "$" << " ";
        else if(mat[i][j] >= 10) cout << "| " << mat[i][j] - 10 << " "; 
        else cout << "| " << " " << " "; 
      } 
    cout << "| ";
      cout << "\n";
    for(int u = 1; u <= 4*n + 1; u = u + 1)
      cout << "-";
      cout << "\n";

  }  
} 
void generareBombe(int bombe, int n, int mat[21][21], int bombaLinie[], int bombaColoana[])
{
  
  for(int i = 1; i <= bombe; ++i)
    {
      int ok = 0; // consideram ca linia si coloana generata nu sunt bune
      while(ok == 0)
        {
          int lBomba, cBomba;
          lBomba = rand() % n + 1;
          cBomba = rand() % n + 1;
          // ca sa verificam daca bomba este una valida trebuie sa verificam ca in matrice
          // pe linia lbomba si coloana cbomba sa nu fie deja o bomba sau playerul, si, daca e goala
          // sa nu aiba vreo bomba drept vecin N S E V
          if(mat[lBomba][cBomba] == 0)
          {
            if(mat[lBomba][cBomba-1] != 1 && mat[lBomba][cBomba + 1] != 1 && 
              mat[lBomba - 1] [cBomba] != 1 && mat[lBomba + 1][cBomba] != 1)
            {
              mat[lBomba][cBomba] = 1;
              ok = 1; // acum am gasit ceva valid pentru bomba noastra
              bombaLinie[i] = lBomba;
              bombaColoana[i] = cBomba;
            }
          }
        }
    }
}
void generateHint(int n, int mat[21][21], int mat2[21][21], int nrBombe, int bl[], int bc[], int &bDezvaluite)
{
  cout << "Puteti obtine informatii pretioase in legatura cu mapa, daca veti raspunde corect la urmatoarea intrebare:\n";
  // generateQuestion();
  char ans[50];
  int q = -1; // q este 0 daca rasp este unic, sau 1 daca poate fi format din mai multe cuvinte
  bool generareIntrebare = false;
  int nrQ;
  while(generareIntrebare == false)
    {
      nrQ = rand() % 150 + 1;
      if(intrebariFolosite[nrQ] == 0) // daca intrebarea nu a fost folosita
      {
        intrebariFolosite[nrQ] = 1;
        generareIntrebare = true;
      }
    }
  
  if(nrQ == 1)
  {
      cout << "Cat face 10 x 10 + 20 + 6 * 5 \n";
      strcpy(ans, "150");
      q = 0;
  }
  else if(nrQ == 2)
  {
      cout << "Care este rezultatul 0 * 6 +  6/6? \n";
      strcpy(ans, "1");
      q = 0;
  }
  else if(nrQ == 3)
  {
      cout << "Cat este x din ecuatia: x + x/2 = 6 \n";
      strcpy(ans, "4");
      q = 0;
  }
  else if(nrQ == 4)
  {
      cout << "Cate grade are un unghi nul \n";
      strcpy(ans, "0");
      q = 0;
  }
  else if(nrQ == 5)
  {
      cout << "Cat este radical din 144 \n";
      strcpy(ans, "12");
      q = 0;
  }
  else if(nrQ == 6)
  {
      cout << "In ce oras se afla 'turnul effiel'?\n";
      strcpy(ans, "Paris");
      q = 0;
  }
  else if(nrQ == 7)
  {
      cout << "Cine este presedintele Romaniei?\n";
      strcpy(ans, "Klauss Iohhanis");
      q = 1;
  }
  else if(nrQ == 8)
  {
      cout << "Care este cea mai mare tara din lume?\n";
      strcpy(ans, "Rusia");
      q = 0;
  }
  else if(nrQ == 9)
  {
      cout << "Care este cel mai mare mamifer din lume?\n";
      strcpy(ans, "Balena albastra");
      q = 1;
  }
  else if(nrQ == 10)
  {
      cout << "Care este cel mai mare continent?\n";
      strcpy(ans, "Asia");
      q = 0;
  }
  else if(nrQ == 11)
  {
      cout << "Care este capitala Italiei?\n";
      strcpy(ans, "Roma");
      q = 0;
  }
  else if(nrQ == 12)
  {
      cout << "Care este cel mai lung fluviu din lume?\n";
      strcpy(ans, "Nil");
      q = 0;
  }
  else if(nrQ == 13)
  {
      cout << "Cate minute are o ora?\n";
      strcpy(ans, "60");
      q = 0;
  }
  else if(nrQ == 14)
  {
      cout << "Cate ore are o zi?\n";
      strcpy(ans, "24");
      q = 0;
  }
  else if(nrQ == 15)
  {
      cout << "Cate zile are o saptamana?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 16)
  {
      cout << "Care este cel mai inalt munte din lume?\n";
      strcpy(ans, "Everest");
      q = 0;
  }
  else if(nrQ == 17)
  {
      cout << "Care este cea mai populata tara?\n";
      strcpy(ans, "China");
      q = 0;
  }
  else if(nrQ == 18)
  {
      cout << "Care este simbolul chimic al apei?\n";
      strcpy(ans, "H2O");
      q = 0;
  }
  else if(nrQ == 19)
  {
      cout << "Cate litere are alfabetul englez?\n";
      strcpy(ans, "26");
      q = 0;
  }
  else if(nrQ == 20)
  {
      cout << "Cate culori are un curcubeu?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 21)
  {
      cout << "Cate continente sunt pe Pamant?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 22)
  {
      cout << "Care este cea mai mare insula din lume?\n";
      strcpy(ans, "Groenlanda");
      q = 0;
  }
  else if(nrQ == 23)
  {
      cout << "Care este capitala Japoniei?\n";
      strcpy(ans, "Tokyo");
      q = 0;
  }
  else if(nrQ == 24)
  {
      cout << "Care este cel mai mare desert din lume?\n";
      strcpy(ans, "Sahara");
      q = 0;
  }
  else if(nrQ == 25)
  {
      cout << "Cate luni are un an?\n";
      strcpy(ans, "12");
      q = 0;
  }
  else if(nrQ == 26)
  {
      cout << "Care este formula chimica a dioxidului de carbon?\n";
      strcpy(ans, "CO2");
      q = 0;
  }
  else if(nrQ == 27)
  {
      cout << "Cate note sunt in gama muzicala?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 28)
  {
      cout << "Care este cel mai rapid animal terestru?\n";
      strcpy(ans, "Ghepard");
      q = 0;
  }
  else if(nrQ == 29)
  {
      cout << "Cate planete sunt in sistemul solar?\n";
      strcpy(ans, "8");
      q = 0;
  }
  else if(nrQ == 30)
  {
      cout << "Care este cel mai adanc punct din oceanele lumii?\n";
      strcpy(ans, "Groapa Marianelor");
      q = 1;
  }
  else if(nrQ == 31)
  {
      cout << "Care este cel mai mare ocean din lume?\n";
      strcpy(ans, "Pacific");
      q = 0;
  }
  else if(nrQ == 32)
  {
      cout << "Care este capitala Frantei?\n";
      strcpy(ans, "Paris");
      q = 0;
  }
  else if(nrQ == 33)
  {
      cout << "Care este cea mai lunga perioada de timp?\n";
      strcpy(ans, "Eon");
      q = 0;
  }
  else if(nrQ == 34)
  {
      cout << "Cate elemente are tabelul periodic?\n";
      strcpy(ans, "118");
      q = 0;
  }
  else if(nrQ == 35)
  {
      cout << "Care este unitatea de masura pentru intensitatea curentului electric?\n";
      strcpy(ans, "Amper");
      q = 0;
  }
  else if(nrQ == 36)
  {
      cout << "Care este capitala Germaniei?\n";
      strcpy(ans, "Berlin");
      q = 0;
  }
  else if(nrQ == 37)
  {
      cout << "Care este capitala Spaniei?\n";
      strcpy(ans, "Madrid");
      q = 0;
  }
  else if(nrQ == 38)
  {
      cout << "Cate continente sunt pe Pamant?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 39)
  {
      cout << "Care este cel mai mic os din corpul uman?\n";
      strcpy(ans, "Scarita");
      q = 0;
  }
  else if(nrQ == 40)
  {
      cout << "Care este cel mai mare organ intern al corpului uman?\n";
      strcpy(ans, "Ficat");
      q = 0;
  }
  else if(nrQ == 41)
  {
      cout << "Care este cel mai mare oras din Statele Unite?\n";
      strcpy(ans, "New York");
      q = 1;
  }
  else if(nrQ == 42)
  {
      cout << "Care este capitala Canadei?\n";
      strcpy(ans, "Ottawa");
      q = 0;
  }
  else if(nrQ == 43)
  {
      cout << "Care este cel mai inalt copac din lume?\n";
      strcpy(ans, "Sequoia");
      q = 0;
  }
  else if(nrQ == 44)
  {
      cout << "Care este cel mai mare animal de pe uscat?\n";
      strcpy(ans, "Elefant");
      q = 0;
  }
  else if(nrQ == 45)
  {
      cout << "Cate luni are un an bisect?\n";
      strcpy(ans, "12");
      q = 0;
  }
  else if(nrQ == 46)
  {
      cout << "Care este cea mai mare planeta din sistemul solar?\n";
      strcpy(ans, "Jupiter");
      q = 0;
  }
  else if(nrQ == 47)
  {
      cout << "Care este cel mai mic stat din lume?\n";
      strcpy(ans, "Vatican");
      q = 0;
  }
  else if(nrQ == 48)
  {
      cout << "Cate zile are luna februarie in anii bisecti?\n";
      strcpy(ans, "29");
      q = 0;
  }
  else if(nrQ == 49)
  {
      cout << "Cate oase are corpul uman adult?\n";
      strcpy(ans, "206");
      q = 0;
  }
  else if(nrQ == 50)
  {
      cout << "Care este cel mai populat oras din lume?\n";
      strcpy(ans, "Tokyo");
      q = 0;
  }
  else if(nrQ == 51)
  {
      cout << "Care este capitala Rusiei?\n";
      strcpy(ans, "Moscova");
      q = 0;
  }
  else if(nrQ == 52)
  {
      cout << "Care este cel mai mare ocean?\n";
      strcpy(ans, "Pacific");
      q = 0;
  }
  else if(nrQ == 53)
  {
      cout << "Care este capitala Mexicului?\n";
      strcpy(ans, "Ciudad de Mexico");
      q = 1;
  }
  else if(nrQ == 54)
  {
      cout << "Care este cea mai inalta cladire din lume?\n";
      strcpy(ans, "Burj Khalifa");
      q = 1;
  }
  else if(nrQ == 55)
  {
      cout << "Cate zile are luna aprilie?\n";
      strcpy(ans, "30");
      q = 0;
  }
  else if(nrQ == 56)
  {
      cout << "Care este cea mai mica planeta din sistemul solar?\n";
      strcpy(ans, "Mercur");
      q = 0;
  }
  else if(nrQ == 57)
  {
      cout << "Care este capitala Australiei?\n";
      strcpy(ans, "Canberra");
      q = 0;
  }
  else if(nrQ == 58)
  {
      cout << "Care este cea mai mare tara din Africa?\n";
      strcpy(ans, "Algeria");
      q = 0;
  }
  else if(nrQ == 59)
  {
      cout << "Care este cel mai mare desert cald din lume?\n";
      strcpy(ans, "Sahara");
      q = 0;
  }
  else if(nrQ == 60)
  {
      cout << "Cate continente sunt pe Pamant?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 61)
  {
      cout << "Care este cel mai lung rau din lume?\n";
      strcpy(ans, "Nil");
      q = 0;
  }
  else if(nrQ == 62)
  {
      cout << "Care este capitala Olandei?\n";
      strcpy(ans, "Amsterdam");
      q = 0;
  }
  else if(nrQ == 63)
  {
      cout << "Care este cel mai mare parc national din lume?\n";
      strcpy(ans, "Parcul National Yellowstone");
      q = 1;
  }
  else if(nrQ == 64)
  {
      cout << "Cine a pictat 'Mona Lisa'?\n";
      strcpy(ans, "Leonardo da Vinci");
      q = 1;
  }
  else if(nrQ == 65)
  {
      cout << "Care este cea mai mare cascada din lume?\n";
      strcpy(ans, "Cascada Angel");
      q = 1;
  }
  else if(nrQ == 66)
  {
      cout << "Care este cel mai mare ocean din lume?\n";
      strcpy(ans, "Oceanul Pacific");
      q = 1;
  }
  else if(nrQ == 67)
  {
      cout << "Cate minute sunt intr-o zi?\n";
      strcpy(ans, "1440");
      q = 0;
  }
  else if(nrQ == 68)
  {
      cout << "Cate zile sunt intr-un an bisect?\n";
      strcpy(ans, "366");
      q = 0;
  }
  else if(nrQ == 69)
  {
      cout << "Care este capitala Argentinei?\n";
      strcpy(ans, "Buenos Aires");
      q = 0;
  }
  else if(nrQ == 70)
  {
      cout << "Cate secunde sunt intr-o ora?\n";
      strcpy(ans, "3600");
      q = 0;
  }
  else if(nrQ == 71)
  {
      cout << "Care este cel mai mic ocean?\n";
      strcpy(ans, "Oceanul Arctic");
      q = 1;
  }
  else if(nrQ == 72)
  {
      cout << "Care este cel mai lung lant muntos din lume?\n";
      strcpy(ans, "Lantul muntos Andes");
      q = 1;
  }
  else if(nrQ == 73)
  {
      cout << "Cate ani a durat primul razboi mondial?\n";
      strcpy(ans, "4");
      q = 0;
  }
  else if(nrQ == 74)
  {
      cout << "Cate ani a durat al doilea razboi mondial?\n";
      strcpy(ans, "6");
      q = 0;
  }
  else if(nrQ == 75)
  {
      cout << "Cate stele sunt pe drapelul Uniunii Europene?\n";
      strcpy(ans, "12");
      q = 0;
  }
  else if(nrQ == 76)
  {
      cout << "Care este cel mai lung rau din Europa?\n";
      strcpy(ans, "Raul Volga");
      q = 1;
  }
  else if(nrQ == 77)
  {
      cout << "Care este cel mai lung pod din lume?\n";
      strcpy(ans, "Podul Danyang-Kunshan");
      q = 1;
  }
  else if(nrQ == 78)
  {
      cout << "Care este capitala Irlandei?\n";
      strcpy(ans, "Dublin");
      q = 0;
  }
  else if(nrQ == 79)
  {
      cout << "Cate tari sunt in Africa?\n";
      strcpy(ans, "54");
      q = 0;
  }
  else if(nrQ == 80)
  {
      cout << "Care este cea mai mare insula din lume?\n";
      strcpy(ans, "Groenlanda");
      q = 0;
  }
  else if(nrQ == 81)
  {
      cout << "Care este cel mai lung fluviu din Europa?\n";
      strcpy(ans, "Raul Volga");
      q = 1;
  }
  else if(nrQ == 82)
  {
      cout << "Care este cel mai inalt munte din Africa?\n";
      strcpy(ans, "Kilimanjaro");
      q = 0;
  }
  else if(nrQ == 83)
  {
      cout << "Care este capitala Norvegiei?\n";
      strcpy(ans, "Oslo");
      q = 0;
  }
  else if(nrQ == 84)
  {
      cout << "Cate litere sunt intr-un alfabet standard?\n";
      strcpy(ans, "26");
      q = 0;
  }
  else if(nrQ == 85)
  {
      cout << "Care este cel mai mare parc de distractii din lume?\n";
      strcpy(ans, "Disneyland");
      q = 1;
  }
  else if(nrQ == 86)
  {
      cout << "Care este cel mai rapid animal pe pamant?\n";
      strcpy(ans, "Ghepard");
      q = 0;
  }
  else if(nrQ == 87)
  {
      cout << "Cate zile sunt intr-un an obisnuit?\n";
      strcpy(ans, "365");
      q = 0;
  }
  else if(nrQ == 88)
  {
      cout << "Cate zile sunt intr-un an bisect?\n";
      strcpy(ans, "366");
      q = 0;
  }
  else if(nrQ == 89)
  {
      cout << "Cate zile sunt intr-un deceniu?\n";
      strcpy(ans, "3652");
      q = 0;
  }
  else if(nrQ == 90)
  {
      cout << "Cate zile sunt intr-un secol?\n";
      strcpy(ans, "36524");
      q = 0;
  }
  else if(nrQ == 91)
  {
      cout << "Care este cel mai lung fluviu din Statele Unite?\n";
      strcpy(ans, "Mississippi");
      q = 1;
  }
  else if(nrQ == 92)
  {
      cout << "Care este cel mai lung tunel din lume?\n";
      strcpy(ans, "Tunelul Laerdal");
      q = 1;
  }
  else if(nrQ == 93)
  {
      cout << "Cate litere are alfabetul rus?\n";
      strcpy(ans, "33");
      q = 0;
  }
  else if(nrQ == 94)
  {
      cout << "Care este cel mai adanc ocean din lume?\n";
      strcpy(ans, "Oceanul Pacific");
      q = 1;
  }
  else if(nrQ == 95)
  {
      cout << "Cate zile sunt intr-o luna bisecta?\n";
      strcpy(ans, "29");
      q = 0;
  }
  else if(nrQ == 96)
  {
      cout << "Care este cel mai adanc lac din lume?\n";
      strcpy(ans, "Lacul Baikal");
      q = 1;
  }
  else if(nrQ == 97)
  {
      cout << "Care este capitala Portugaliei?\n";
      strcpy(ans, "Lisabona");
      q = 0;
  }
  else if(nrQ == 98)
  {
      cout << "Cate zile are un an bisect?\n";
      strcpy(ans, "366");
      q = 0;
  }
  else if(nrQ == 99)
  {
      cout << "Care este cel mai vechi oras din lume?\n";
      strcpy(ans, "Damasc");
      q = 0;
  }
  else if(nrQ == 100)
  {
      cout << "Care este cel mai adanc canion din lume?\n";
      strcpy(ans, "Canionul Colorado");
      q = 1;
  }
  else if(nrQ == 101)
  {
      cout << "Cate tari sunt in Uniunea Europeana?\n";
      strcpy(ans, "27");
      q = 0;
  }
  else if(nrQ == 102)
  {
      cout << "Care este cel mai mic munte din lume?\n";
      strcpy(ans, "Muntele Everest");
      q = 0;
  }
  else if(nrQ == 103)
  {
      cout << "Care este cel mai mare rau din Africa?\n";
      strcpy(ans, "Nil");
      q = 1;
  }
  else if(nrQ == 104)
  {
      cout << "Care este cel mai mare crater din lume?\n";
      strcpy(ans, "Craterul Barringer");
      q = 1;
  }
  else if(nrQ == 105)
  {
      cout << "Cate stele sunt pe drapelul american?\n";
      strcpy(ans, "50");
      q = 0;
  }
  else if(nrQ == 106)
  {
      cout << "Cate versete sunt in Coran?\n";
      strcpy(ans, "6666");
      q = 0;
  }
  else if(nrQ == 107)
  {
      cout << "Care este cel mai mare oras din lume?\n";
      strcpy(ans, "Tokyo");
      q = 0;
  }
  else if(nrQ == 108)
  {
      cout << "Cate tari sunt in America de Nord?\n";
      strcpy(ans, "23");
      q = 0;
  }
  else if(nrQ == 109)
  {
      cout << "Care este cel mai mic ocean din lume?\n";
      strcpy(ans, "Oceanul Arctic");
      q = 1;
  }
  else if(nrQ == 110)
  {
      cout << "Cate ore sunt intr-o zi?\n";
      strcpy(ans, "24");
      q = 0;
  }
  else if(nrQ == 111)
  {
      cout << "Care este cel mai mare stat din lume?\n";
      strcpy(ans, "Rusia");
      q = 0;
  }
  else if(nrQ == 112)
  {
      cout << "Cate secunde sunt intr-un minut?\n";
      strcpy(ans, "60");
      q = 0;
  }
  else if(nrQ == 113)
  {
      cout << "Cate secunde sunt intr-o ora?\n";
      strcpy(ans, "3600");
      q = 0;
  }
  else if(nrQ == 114)
  {
      cout << "Cate zile sunt intr-o saptamana?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 115)
  {
      cout << "Cate luni sunt intr-un an obisnuit?\n";
      strcpy(ans, "12");
      q = 0;
  }
  else if(nrQ == 116)
  {
      cout << "Cate zile sunt intr-un an obisnuit?\n";
      strcpy(ans, "365");
      q = 0;
  }
  else if(nrQ == 117)
  {
      cout << "Cate zile sunt intr-o saptamana?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 118)
  {
      cout << "Care este capitala Irlandei?\n";
      strcpy(ans, "Dublin");
      q = 0;
  }
  else if(nrQ == 119)
  {
      cout << "Cate tari sunt in lume?\n";
      strcpy(ans, "195");
      q = 0;
  }
  else if(nrQ == 120)
  {
      cout << "Care este cel mai adanc ocean din lume?\n";
      strcpy(ans, "Oceanul Pacific");
      q = 1;
  }
  else if(nrQ == 121)
  {
      cout << "Cate zile sunt intr-un an bisect?\n";
      strcpy(ans, "366");
      q = 0;
  }
  else if(nrQ == 122)
  {
      cout << "Cate ore sunt intr-o zi?\n";
      strcpy(ans, "24");
      q = 0;
  }
  else if(nrQ == 123)
  {
      cout << "Care este cel mai inalt munte din lume?\n";
      strcpy(ans, "Muntele Everest");
      q = 0;
  }
  else if(nrQ == 124)
  {
      cout << "Cate tari sunt in Uniunea Europeana?\n";
      strcpy(ans, "27");
      q = 0;
  }
  else if(nrQ == 125)
  {
      cout << "Care este capitala Pakistanului?\n";
      strcpy(ans, "Islamabad");
      q = 0;
  }
  else if(nrQ == 126)
  {
      cout << "Cate oase are un adult in corpul uman?\n";
      strcpy(ans, "206");
      q = 0;
  }
  else if(nrQ == 127)
  {
      cout << "Care este cel mai mare animal terestru?\n";
      strcpy(ans, "Elefantul African");
      q = 1;
  }
  else if(nrQ == 128)
  {
      cout << "Cate zile are o saptamana?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 129)
  {
      cout << "Care este cea mai mare tara din Africa?\n";
      strcpy(ans, "Algeria");
      q = 0;
  }
  else if(nrQ == 130)
  {
      cout << "Cate zile sunt intr-un an obisnuit?\n";
      strcpy(ans, "365");
      q = 0;
  }
  else if(nrQ == 131)
  {
      cout << "Care este capitala Thailandei?\n";
      strcpy(ans, "Bangkok");
      q = 0;
  }
  else if(nrQ == 132)
  {
      cout << "Cate litere sunt in alfabetul englez?\n";
      strcpy(ans, "26");
      q = 0;
  }
  else if(nrQ == 133)
  {
      cout << "Cate state sunt in Statele Unite?\n";
      strcpy(ans, "50");
      q = 0;
  }
  else if(nrQ == 134)
  {
      cout << "Care este cea mai mare cascada din lume?\n";
      strcpy(ans, "Cascada Angel");
      q = 1;
  }
  else if(nrQ == 135)
  {
      cout << "Cate litere sunt intr-un alfabet standard?\n";
      strcpy(ans, "26");
      q = 0;
  }
  else if(nrQ == 136)
  {
      cout << "Cate continente sunt pe Pamant?\n";
      strcpy(ans, "7");
      q = 0;
  }
  else if(nrQ == 137)
  {
      cout << "Care este cel mai adanc punct de pe Pamant?\n";
      strcpy(ans, "Groapa Marianelor");
      q = 1;
  }
  else if(nrQ == 138)
  {
      cout << "Care este cel mai lung fluviu din lume?\n";
      strcpy(ans, "Nil");
      q = 1;
  }
  else if(nrQ == 139)
  {
      cout << "Care este capitala Vietnamului?\n";
      strcpy(ans, "Hanoi");
      q = 0;
  }
  else if(nrQ == 140)
  {
      cout << "Cate zile sunt intr-un an bisect?\n";
      strcpy(ans, "366");
      q = 0;
  }
  else if(nrQ == 141)
  {
      cout << "Cate litere sunt in alfabetul rus?\n";
      strcpy(ans, "33");
      q = 0;
  }
  else if(nrQ == 142)
  {
      cout << "Cate state sunt in Statele Unite?\n";
      strcpy(ans, "50");
      q = 0;
  }
  else if(nrQ == 143)
  {
      cout << "Cate ore sunt intr-o zi?\n";
      strcpy(ans, "24");
      q = 0;
  }
  else if(nrQ == 144)
  {
      cout << "Cate tari sunt in Europa?\n";
      strcpy(ans, "50");
      q = 0;
  }
  else if(nrQ == 145)
  {
      cout << "Care este capitala Spaniei?\n";
      strcpy(ans, "Madrid");
      q = 0;
  }
  else if(nrQ == 146)
  {
      cout << "Cate litere sunt in alfabetul englez?\n";
      strcpy(ans, "26");
      q = 0;
  }
  else if(nrQ == 147)
  {
      cout << "Cate zile sunt intr-un an obisnuit?\n";
      strcpy(ans, "365");
      q = 0;
  }
  else if(nrQ == 148)
  {
      cout << "Care este cel mai mare oras din lume?\n";
      strcpy(ans, "Tokyo");
      q = 0;
  }
  else if(nrQ == 149)
  {
      cout << "Cate litere sunt in alfabetul chinez?\n";
      strcpy(ans, "0");
      q = 0;
  }
  else if(nrQ == 150)
  {
      cout << "Cate zile sunt intr-un an bisect?\n";
      strcpy(ans, "366");
      q = 0;
  }

  int startTime = time(NULL);
  int stopTime = time(NULL) + 20;
  char answer[50]; // nu s-a primit raspuns
  answer[0] = '\0';
  cin.get();
  cin.getline(answer, 50);
  
  int ok = 0;
  while(time(NULL) <= stopTime && ok == 0)
    {
      if(answer[0] != '\0')
      {
        ok = 1;
      }
    }
  if(ok == 0)
    cout << "Timpul dvs de raspuns a fost de " << time(NULL) - startTime << " secunde! Raspunsul nu este valid, nu veti primi indiciu!\n" << "Raspunsul era: " << ans << "\n";
  else 
    if((q == 0 && strcmp(answer, ans) == 0)
      || (q == 1 && strstr(ans, answer) != NULL))
  {
    cout << "Felicitari! Ati primit un indiciu!\n";

    // trebuie sa afisam o informatie, fie bomba, fie o casuta cu informatii 
    int alegere = rand() % 2; // poate fi 0, daca dezvaluim bomba, sau 1 altfel

    if(alegere == 0 && bDezvaluite < nrBombe)
    {
    ++bDezvaluite;
    int ok = 0;
    while(ok == 0)
      {
        int nrBombaDezvaluita = rand() % nrBombe + 1;
        if(bl[nrBombaDezvaluita] != -1)
        {
          // adica bomba nu a fost dezvaluita inainte

          mat[bl[nrBombaDezvaluita]][bc[nrBombaDezvaluita]] = -1; // am dezvaluut bomba
          bl[nrBombaDezvaluita] = -1;
          bc[nrBombaDezvaluita] = -1;
          ok = 1;
        }
      }
    }
    else
    {
      int ok = 0;
      while(ok == 0)
        {
          int idezv = rand() % n +1;
          int jdezv = rand() % n +1;
          if(mat[idezv][jdezv] == 0)
          {
            mat[idezv][jdezv] = 10;
            // trebuie sa ii toti cei 8 vecini(Daca EXISTA) si sa verificam cate bombe sunt

            if(abs(mat[idezv-1][jdezv-1]) == 1) mat[idezv][jdezv]++;
            if(abs(mat[idezv-1][jdezv]) == 1) mat[idezv][jdezv]++;
            if(abs(mat[idezv-1][jdezv+1]) == 1) mat[idezv][jdezv]++;
            if(abs(mat[idezv][jdezv+1]) == 1 ) mat[idezv][jdezv]++;
            if(abs(mat[idezv+1][jdezv+1]) == 1) mat[idezv][jdezv]++;
            if(abs(mat[idezv+1][jdezv]) == 1) mat[idezv][jdezv]++;
            if(abs(mat[idezv+1][jdezv-1]) == 1) mat[idezv][jdezv]++;
            if(abs(mat[idezv][jdezv-1]) == 1) mat[idezv][jdezv]++;
            mat2[idezv][jdezv] = mat[idezv][jdezv]; 
            ok = 1;
          }
          
        }
    }

    afisaretablaHide(n, mat, mat2);
  }

  else
  {
    cout << "Raspuns gresit! Nu cunoasteti informatii suplimentare despre mapa! Raspunsul era: " << ans << "\n";
    afisaretablaHide(n, mat, mat2);
  }
  

  
}
void run(int liniestart, int coloanastart, int n, int mat[21][21], int mat2[21][21], int nrBombe, int bl[], int bc[], int &bDezvaluite)
{
  char optiune;
  int dead = 0; // momentan playerul nu a murit
  while(dead == 0)
    {
      generateHint(n, mat, mat2, nrBombe, bl, bc, bDezvaluite);
      cout << "Introduceti w daca vreti sa avansati in sus, s in jos, d in dreapta si a in stanga\n";
      cin >> optiune;
      mat[liniestart][coloanastart] = mat2[liniestart][coloanastart];
      switch(optiune)
        {
          case 'w' :
            liniestart = liniestart - 1;
            break;
          case 'd' : 
            coloanastart = coloanastart + 1;
            break;
          case 's' : 
            liniestart = liniestart + 1;
            break;
          default :
           coloanastart = coloanastart - 1;
            break;  
        }
      if(mat[liniestart][coloanastart] == 1 || mat[liniestart][coloanastart] == -1)
        dead = 1;
      else if (mat[liniestart][coloanastart] == 6)
        dead = 2;
      else mat[liniestart][coloanastart] = 5;
      afisaretablaHide(n, mat, mat2);
    }
  if(dead == 1)
  cout << "AI MURIT!\n";
  else cout << "FELICITARI! AI IESIT DIN LABIRINT!\n";
  afisaretabla(n, mat);
}
void generateExit(int n, int mat[21][21])
{

  // vrem sa generam poarta
  int ok = 0;
  while(ok == 0)
    {
      int liniestart = rand() % n + 1;
      int coloanastart = rand() % n + 1;
      if(mat[liniestart][coloanastart] == 0)
      {
        mat[liniestart][coloanastart] = 6;
        ok = 1; // pentru ca poarta a fost generata si ne oprim din while
      }
    }
  
}

int validSolution(int n, int mat[21][21])
{

  // returneaza 0 daca pentru matricea existenta nu exista drum de la start la stop
  // returneaza 1 daca exista
  return 0;
  
}
int main(){
  int n, mat[21][21], mat2[21][21], GradDif, liniestart, coloanastart, spawn, Bombe, i, j;
  int bombaLinie[400], bombaColoana[400], bDezvaluite = 0;
  
  cout << "START JOC\n\n";
  cout << "Acest joc se numeste minesweeper, alege cate linii si coloane sa fie.\n";
  cout << "Maximul de linii / coloane este de 10, si minimul este de 4.\n";
  cin >> n;
  InitMap(n, mat, mat2);
  cout << "\n";
  cout << "Ce dificultate ai vrea sa fie jocul ?\n";
  cout << "0 pentru usor, 1 pentru mediu si 2 pentru greu.";
  cin >> GradDif;
  
  spawnare(n, mat, liniestart, coloanastart);

  if(GradDif == 0)
    Bombe = rand() % (n*n) / 2 + 1;
  if(GradDif == 1)
     Bombe = rand() % (n*n) / 2 + (n*n/3);
  if(GradDif == 2)
    Bombe = rand() % (n*n) / 2 + (n*n)/2;
  generateExit(n, mat);


  generareBombe(Bombe, n, mat, bombaLinie, bombaColoana);

  afisaretablaHide(n, mat, mat2);

  run(liniestart, coloanastart, n, mat, mat2, Bombe, bombaLinie, bombaColoana, bDezvaluite);
  // cout << "                         oooo$$$$$$$$$$$$oooo\n";
  // cout << "                      oo$$$$$$$$$$$$$$$$$$$$$$$$o\n";
  // cout << "                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o        \n";
  // cout << "                o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o      \n";
  // cout << "               o$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$o       \n";
  // cout << "               o$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$o    \n";
  // cout << "               $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$\n";
  // cout << "            $$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  \n";
  // cout << "         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   \n";
  // cout << "          o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     \n";
  // cout << "           $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      \n";
  // cout << "             $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \"\n";
  // cout << "          $$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n";
  // cout << "            \"$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$\n";
  // cout << "          $$$$    \"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\"      o$$$\n";
  // cout << "            \"$$$o     \"\"\"$$$$$$$$$$$$$$$$$$\"$$\"         $$$\n";
  // cout << "              $$$o          \"$$\"\"$$$$$$\"\"\"           o$$$\n";
  // cout << "               $$$$o                 oo             o$$$\"\n";
  // cout << "                \"$$$$o      o$$$$$$o\"$$$$o        o$$$$\n";
  // cout << "                  \"$$$$$oo     \"\"$$$$o$$$$$o   o$$$$\"\"  \n";
  // cout << "                     \"\"$$$$$oooo  \"$$$o$$$$$$$$$\"\"\"\n";
  // cout << "                        \"\"$$$$$$$oo $$$$$$$$$$       \n";
  // cout << "                                \"\"\"\"$$$$$$$$$$$        \n";
  // cout << "                                    $$$$$$$$$$$$       \n";
  // cout << "                                     $$$$$$$$$$\"      \n";
  // cout << "                                      \"$$$\"\"\"\"\" \n";
 

  return 0;
}