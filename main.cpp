#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
void InitMap(int n, int mat[11][11]){
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      mat[i][j] = 0;
}
void spawnare(int n, int mat[11][11], int &liniestart, int &coloanastart)
{
    liniestart = rand() % n + 1;
    coloanastart = rand() % n + 1;
    mat[liniestart][coloanastart] = 5;
}
void afisaretabla(int n, int mat[11][11]){

  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    for(int u = 1; u <= 4*n + 1; u = u + 1)
      cout << "-";
      cout << "\n";
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
          if(mat[i][j] == 6)
            cout << "| " << "#" << " ";
          else if(mat[i][j]  == 0)
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
void afisaretablaHide(int n, int mat[11][11]){

cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
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
          cout << lBomba << " " << cBomba << "\n";
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
void generateHint(int n, int mat[11][11], int nrBombe, int bl[], int bc[], int &bDezvaluite)
{
  cout << "Puteti obtine informatii pretioase in legatura cu mapa, daca veti raspunde corect la urmatoarea intrebare:";
  // generateQuestion();
  int nrQ = rand() % 3 + 1;
  if(nrQ == 1)
    cout << "Cat face 10 x 10 + 20 + 6 * 5\n";
  else cout << "Care este rezultatul 0 * 6 +  6/6?\n";

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
  else
  {
    cout << "Felicitari! Ati primit un indiciu!\n";
    ++bDezvaluite;
    int ok = 0;
    if(bDezvaluite <= nrBombe)
    {
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
      cout << "Nu mai sunt indicii de aratat!\n";
    }

    afisaretablaHide(n, mat);
  }
  

  
}
void run(int liniestart, int coloanastart, int n, int mat[11][11], int nrBombe, int bl[], int bc[], int &bDezvaluite)
{
  char optiune;
  int dead = 0; // momentan playerul nu a murit
  while(dead == 0)
    {
      generateHint(n, mat, nrBombe, bl, bc, bDezvaluite);
      cout << "Introduceti w daca vreti sa avansati in sus, s in jos, d in dreapta si a in stanga\n";
      cin >> optiune;
      mat[liniestart][coloanastart] = 0;
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
      if(mat[liniestart][coloanastart] == 1)
        dead = 1;
      else mat[liniestart][coloanastart] = 5;
      afisaretablaHide(n, mat);
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
  int n, mat[11][11], GradDif, liniestart, coloanastart, spawn, Bombe, i, j;
  int bombaLinie[20], bombaColoana[20], bDezvaluite = 0;
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  cout << "Acest joc se numeste minesweeper, alege cate linii si coloane sa fie.\n";
  cout << "Maximul de linii / coloane este de 10, si minimul este de 4.\n";
  cin >> n;
  InitMap(n, mat);
  cout << "\n";
  cout << "Ce dificultate ai vrea sa fie jocul ?\n";
  cout << "0 pentru usor, 1 pentru mediu si 2 pentru greu.";
  cin >> GradDif;
  cout << "Test 1 \n";
  spawnare(n, mat, liniestart, coloanastart);

  cout << "Test 2 \n";
  if(GradDif == 0)
    Bombe = rand() % n/2 + 1; // o sa returneze o valoare de la 0 la n/2-1
  if(GradDif == 1)
    Bombe = rand() % n/2  + n / 3;
  if(GradDif == 2)
    Bombe = rand() % n / 2 + n/2;
  generateExit(n, mat);

  cout << Bombe << "\n";
  cout  << "Test 3\n";
  generareBombe(Bombe, n, mat, bombaLinie, bombaColoana);

  cout << "Test 4 \n";
  afisaretablaHide(n, mat);

  for(int i = 1; i <= Bombe; ++i)
    {
      cout << "Bomba cu nr: " << i <<" se afla pe linia " << bombaLinie[i] << " si coloana" << bombaColoana[i] << "\n";
    }
  run(liniestart, coloanastart, n, mat, Bombe, bombaLinie, bombaColoana, bDezvaluite);
  
 

  return 0;
}