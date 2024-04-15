#include <iostream> 
#include <fstream>
#include <string>


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
    // argv[1] é o nome do arquivo binário e argv[2] é um inteiro entre 0 e 999.
    if (argc != 3)
    {
        std::cout << "Uso: " << argv[0] << " <arquivo_binário>.csv inteiro" << std::endl;
        return 1;
    }

    std::string NomeArquivoTexto = argv[1];
    int  movie_id = stoi(string(argv[2]));

    if(movie_id < 0 || movie_id > 49){
        std::cout << "O inteiro deve estar entre 0 e 49" << std::endl;
        return 1;
    }
    
    long long posicao = sizeof(Movie) * movie_id;

    Movie movie;
    ifstream arquivo;
    arquivo.open(NomeArquivoTexto, ios::binary);
    
     arquivo.seekg(posicao, ios::beg);
    if (!arquivo) {
        cout << "Erro ao posicionar o ponteiro do arquivo." << endl;
        arquivo.close();
        return 1;
    }

    arquivo.read((char*)&movie, sizeof(Movie));
    if (!arquivo) {
        cout << "Erro ao ler os dados do arquivo." << endl;
        arquivo.close();
        return 1;
    }


    cout << "Movie Name: " << movie.name<<endl;
    cout << "Year of release: " << movie.year<<endl;
    cout << "Movie Rating: " << movie.rating<<endl;
    cout << "Metascore of Movie: " << movie.metascore<<endl;
    cout << "Gross Earnings: " << movie.earnings<<endl;

    arquivo.close();
    return 0;
}