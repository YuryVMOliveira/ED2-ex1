#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
struct Movie {
    char name[50];
    int year;
    int watchTime;
    float rating;
    int metascore;
    float earnings;    
};

int main(int argc, char* argv[])
{

    // o programa obrigatoriamente recebe dois argumentos por linha de comando
    // argv[1] é o nome do arquivo de entrada e argv[2] é o nome do arquivo de saída
    if (argc != 3)
    {
        cout << "Uso: " << argv[0] << " <arquivo_entrada>.csv <arquivo_saida>.dat" << endl;
        return 1;
    }

    string NomeArquivoTexto = argv[1];
    string NomeArquivoBinario = argv[2];
    ifstream entrada(NomeArquivoTexto);
     if(!entrada.is_open()) {
     cout << "Erro ao abrir o arquivo de entrada!" << endl;
     return 0;
  }

  ofstream saida(NomeArquivoBinario, ios::binary);
  if (!saida) {
        cout << "Erro ao criar o arquivo de saída." << endl;
        return 1;
    }
    string linha;
    getline(entrada, linha);
 
    int i = 0;
    while(getline(entrada, linha)) // Lê uma linha por vez do arquivo
  {
      Movie movie;
      stringstream ss(linha); // Cria um stringstream a partir da linha

      string id;
      getline(ss, id, ',');

    char primeiroCaractere;
    ss.get(primeiroCaractere);
    ss.seekg(-1, ios_base::cur);
    if (primeiroCaractere == '"')
    {
        ss.seekg(1, ios_base::cur);
        string tempName;
        getline(ss, tempName, '"');
        strcpy(movie.name, tempName.c_str());
        ss.seekg(1, ios_base::cur);
         }else if(primeiroCaractere==','){
             return 0;
        }
       else{
            string tempName;
            getline(ss, tempName, ',');
            strcpy(movie.name, tempName.c_str());
        }
      

        string tempYear;
        getline(ss, tempYear, ',');
        movie.year = stoi(tempYear);

        string tempWatchTime;
        getline(ss, tempWatchTime, ',');
        movie.watchTime = stoi(tempWatchTime);

        string tempRating;
        getline(ss, tempRating, ',');
        movie.rating = stof(tempRating);

        string tempMetascore;
        getline(ss, tempMetascore, ',');
        movie.metascore = stoi(tempMetascore);

        string tempEarnings;
        getline(ss, tempEarnings, ',');
        movie.earnings = stof(tempEarnings);

        i++;
        
        saida.write((char *)&movie, sizeof(Movie));
  }
  saida.close();
  entrada.close();

  return 0;

}
