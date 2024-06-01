#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
void InitMap(int n, int mat[11][11], int mat2[11][11]){
  for(int i = 0; i <= n+1; ++i)
    for(int j = 0; j <= n+1; ++j)
      { mat[i][j] = 0; mat2[i][j] = 0;}
}
void spawnare(int n, int mat[11][11], int &liniestart, int &coloanastart)
{
    srand(time(0)); 
    liniestart = rand() % n + 1;
    coloanastart = rand() % n + 1;
    mat[liniestart][coloanastart] = 5;
}
void afisaretabla(int n, int mat[11][11]){

  cout << "\n\n\n\--------------------------------------\n\n";
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
void afisaretablaHide(int n, int mat[11][11], int mat2[11][11]){

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
void generareBombe(int bombe, int n, int mat[11][11], int bombaLinie[], int bombaColoana[])
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
void generateHint(int n, int mat[11][11], int mat2[11][11], int nrBombe, int bl[], int bc[], int &bDezvaluite)
{
  cout << "Puteti obtine informatii pretioase in legatura cu mapa, daca veti raspunde corect la urmatoarea intrebare:\n";
  // generateQuestion();
  int ans;
  int nrQ = rand() % 5 + 1;
  if(nrQ == 1)
  {
    cout << "Cat face 10 x 10 + 20 + 6 * 5 \n";
    ans = 150;
  }
  else if(nrQ == 2)
  {
  cout << "Care este rezultatul 0 * 6 +  6/6? \n";
  ans = 1;
  }
  else if(nrQ == 3)
    {
    cout << "Cat este x din ecuatia: x + x/2 = 6 \n";
    ans = 4;
    }
  else if(nrQ == 4)
    {
    cout << "Cate grade are un unghi nul \n";
    ans = 0;
    }
  else if(nrQ == 5)
    {
    cout << "Cat este radical din 144 \n";
    ans = 12;
    }

  int startTime = time(NULL);
  int stopTime = time(NULL) + 10;
  int answer = -1; // nu s-a primit raspuns
  cin >> answer;
  int ok = 0;
  while(time(NULL) <= stopTime && ok == 0)
    {
      if(answer != -1)
      {
        ok = 1;
      }
    }

  if(ok == 0)
    cout << "Timpul dvs de raspuns a fost de " << time(NULL) - startTime << " secunde! Raspunsul nu este valid, nu veti primi indiciu!\n";
  else if(answer == ans)
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
    cout << "Raspuns gresit! Nu cunoasteti informatii suplimentare despre mapa! \n";
    afisaretablaHide(n, mat, mat2);
  }
  

  
}
void run(int liniestart, int coloanastart, int n, int mat[11][11], int mat2[11][11], int nrBombe, int bl[], int bc[], int &bDezvaluite)
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
      else mat[liniestart][coloanastart] = 5;
      afisaretablaHide(n, mat, mat2);
    }
  cout << "AI MURIT!";
  afisaretabla(n, mat);
}
void generateExit(int n, int mat[11][11])
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

int validSolution(int n, int mat[11][11])
{

  // returneaza 0 daca pentru matricea existenta nu exista drum de la start la stop
  // returneaza 1 daca exista

  
}
int main(){
  int n, mat[11][11], mat2[11][11], GradDif, liniestart, coloanastart, spawn, Bombe, i, j;
  int bombaLinie[20], bombaColoana[20], bDezvaluite = 0;
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
    Bombe = rand() % n/2 + 1; // o sa returneze o valoare de la 0 la n/2-1
  if(GradDif == 1)
    Bombe = rand() % n/2  + n / 3;
  if(GradDif == 2)
    Bombe = rand() % n / 2 + n/2;
  generateExit(n, mat);


  generareBombe(Bombe, n, mat, bombaLinie, bombaColoana);

  afisaretablaHide(n, mat, mat2);

  run(liniestart, coloanastart, n, mat, mat2, Bombe, bombaLinie, bombaColoana, bDezvaluite);
  
 

  return 0;
}