#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
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
          if(mat[i][j]  == 0)
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
void generareBombe(int bombe, int n, int mat[11][11])
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
            }
          }
        }
    }
}

void run(int liniestart, int coloanastart, int n, int mat[11][11])
{
  char optiune;
  int dead = 0; // momentan playerul nu a murit
  while(dead == 0)
    {
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
      afisaretabla(n, mat);
    }
  cout << "AI MURIT!";
}
int main(){
  int n, mat[11][11], GradDif, liniestart, coloanastart, spawn, Bombe, i, j;
  cout << "Acest joc se numeste minesweeper, alege cate linii si coloane sa fie.\n";
  cout << "Maximul de linii / coloane este de 10, si minimul este de 4.\n";
  cin >> n;
  InitMap(n, mat);
  cout << "\n";
  afisaretabla(n, mat);
  cout << "Ce dificultate ai vrea sa fie jocul ?\n";
  cout << "0 pentru usor, 1 pentru mediu si 2 pentru greu.";
  cin >> GradDif;
  spawnare(n, mat, liniestart, coloanastart);
  if(GradDif == 0)
    Bombe = rand() % n/2 + 1; // o sa returneze o valoare de la 0 la n/2-1
  if(GradDif == 1)
    Bombe = rand() % n/2  + n / 2 + 1;
  if(GradDif == 2)
    Bombe = rand() % n / 2 + n + 1;
  generareBombe(Bombe, n, mat);
  afisaretabla(n, mat);
  run(liniestart, coloanastart, n, mat);
  
 

  return 0;
}