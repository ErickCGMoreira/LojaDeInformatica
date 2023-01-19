#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;
fstream fin, fout;

void listar(int tipo, string a, string b) {
	
	system("cls");
	
	switch (tipo){
		
		case 1:
			fin.open("produtos.csv", ios::in);
			break;
		
		case 2:
			fin.open("clientes.csv", ios::in);
			break;
		
		case 3:
			fin.open("fornecedores.csv", ios::in);
			break;
		
		case 4:
			fin.open("parceiros.csv", ios::in);
			break;
		
	}
	
	vector<string> dados;
    string linha, palavra, temp;
    
    cout << "==============> Lista de " << a << " Cadastrados <================ \n\n";
  
    while (fin >> temp) {
  
        dados.clear();

        getline(fin, linha);
  
        stringstream s(linha);
  
        while (getline(s, palavra, ',')) {
			dados.push_back(palavra);
        }

		cout << "==============> " << b << " " << dados[0] << " <================ \n\n";
		
            cout << "Nome: " << dados[1] << "\n";
            cout << "Telefone: " << dados[2] << "\n";
            cout << "E-mail: " << dados[3] << "\n";
            cout << "Idade: " << dados[4] << "\n";
            cout << "CPF: " << dados[5] << "\n";
            
        cout << "======================================================== \n\n";
        	
	}

}

void procurar(int tipo, string a, string b) {
	
	system("cls");
	
	switch (tipo){
		
		case 1:
			fin.open("produtos.csv", ios::in);
			break;
		
		case 2:
			fin.open("clientes.csv", ios::in);
			break;
		
		case 3:
			fin.open("fornecedores.csv", ios::in);
			break;
		
		case 4:
			fin.open("parceiros.csv", ios::in);
			break;
		
	}
	
	cout << "===================> Pesquisar " << a << " <================== \n\n";
    
    int codigo_pesquisado, codigo_atual, controle = 0;
    
    vector<string> dados;
    string linha, palavra, temp;
  
    int codigo = 0;
  
  	while(fin >> temp) {
	  
	    dados.clear();
	
	    getline(fin, linha);
	
	    stringstream s(linha);

	    while (getline(s, palavra, ',')) {
			dados.push_back(palavra);
	    }
	    codigo = stoi(dados[0]); 
	}

	switch (tipo){
		
		case 1:
			fout.open("produtos.csv", ios::out | ios::app);
			break;
			
		case 2:
			fout.open("clientes.csv", ios::out | ios::app);
			break;
			
		case 3:
			fout.open("fornecedores.csv", ios::out | ios::app);
			break;
			
		case 4:
			fout.open("parceiros.csv", ios::out | ios::app);
			break;
		
	}
}

void cadastrar(int tipo, string a, string b) {
	
	system("cls");
	
	switch (tipo){
		
		case 1:
			fin.open("produtos.csv", ios::in);
			break;
		
		case 2:
			fin.open("clientes.csv", ios::in);
			break;
		
		case 3:
			fin.open("fornecedores.csv", ios::in);
			break;
		
		case 4:
			fin.open("parceiros.csv", ios::in);
			break;
		
	}
	
	cout << "===================> Cadastrar Novos " << a << " <================== \n\n";
    
    vector<string> dados;
    string linha, palavra, temp;
  
    int codigo = 0;
  
  	while(fin >> temp) {
	  
	    dados.clear();
	
	    getline(fin, linha);
	
	    stringstream s(linha);

	    while (getline(s, palavra, ',')) {
			dados.push_back(palavra);
	    }
	    codigo = stoi(dados[0]); 
	}

	switch (tipo){
		
		case 1:
			fout.open("produtos.csv", ios::out | ios::app);
			break;
			
		case 2:
			fout.open("clientes.csv", ios::out | ios::app);
			break;
			
		case 3:
			fout.open("fornecedores.csv", ios::out | ios::app);
			break;
			
		case 4:
			fout.open("parceiros.csv", ios::out | ios::app);
			break;
		
	}
    
    string resposta;
    	
    codigo++;
    
  	cout << "===========> Adicionar " << b << " " << codigo << " <============== \n\n";
  	
  	cout << "Informe o NOME do " << b << ": ";
    cin >> resposta;
    fout << ", " << "Nome: " << resposta;
        
	if (tipo != 1){
       	cout << "Informe o CPF / CNPJ do " << b <<": ";
    	cin >> resposta;
        fout << ", " << "CPF/CNPJ: " << resposta;
    	    
        cout << "Informe o TELEFONE do " << b << ": ";
        cin >> resposta;
    	fout << ", " << "Telefone: " << resposta;
        	
        cout << "Informe o E-MAIL do " << b << ": ";
        cin >> resposta;
        fout << ", " << "E-mail: " << resposta;
       	 
        if (tipo == 3){
        	
        	cout << "Informe o TIPO DE PRODUTO  fornecido: ";
        	cin >> resposta;
        	fout << ", " << "Tipo de produto fornecido: " << resposta;
        	
		} else if (tipo == 2) {
			
			cout << "Informe a IDADE do " << b << ": ";
        	cin >> resposta;
			fout << ", " << "Idade: " << resposta;
			
		}
        
    } else {
    		
    	cout << "Informe a CATEGORIA do " << b << ": ";
        cin >> resposta;
        fout << ", " << "Categoria: " << resposta;
    		
    	cout << "Informe a MARCA do " << b << ": ";
        cin >> resposta;
        fout << ", " << "Marca: " << resposta;
    		
    	cout << "Informe o PREÇO do " << b << ": ";
        cin >> resposta;
        fout << ", " << "Preço: " << resposta;
        	
        cout << "Informe a QUANTIDADE EM ESTOQUE do " << b << ": ";
        cin >> resposta;
        fout << ", " << "Em estoque: " << resposta;
    		
    	cout << "O produto esta anunciado em algum site?   1 | SIM 2 | NAO   ";
        cin >> resposta;
        	
        if (resposta == "1" or resposta == "sim"){
        		
        	cout << "Informe o SITE onde o produto esta listado: ";
    		cin >> resposta;
    		fout << ", " << "Listado no site: " << resposta;
        		
		} else {
				
			fout << ", " << "Loja física";
			
		}
    		
	}
		
	fout << "\n";

    cout << "=======================================================> \n\n";
    
	cout << "Dados Gravados com Sucesso! \n";
}

int main(){
	
	setlocale(LC_ALL, "portuguese");
	int resposta, l = 9;
	
	/* TODO (#2#): login
 */
	
	/* TODO (#3#): tela inicial
 */
	
	while (l != 0){

		cout << "===================> Menu Principal <=================== \n\n";
		cout << "Digite o numero da opção desejada:  \n";
		cout << " 1 | Vendas   2 | Produtos   3 | Clientes   4 | Fornecedores    5 | Parceiros    6 | Ajuda   7 | Sobre \n" << "=> ";
		cin >> resposta;
	
		switch (resposta){
		
			case 1:
				/* TODO (#1#): vendas*/
				break;
			
			case 2:
				cout << "Digite o numero da opção desejada: 1 | Listar todos os produtos   2 | Pesquisar um produto   3 | Cadastrar um novo produto   4 | Excluir um produto /n" << "=> ";
				cin >> resposta;
			
				switch (resposta){
				
					case 1:
						/* TODO (#1#): lista */
						break;
						
					case 2:
						/* TODO (#1#): pesquisar */
						break;
						
					case 3:
						cadastrar(1, "Produtos", "produto");
						break;
						
					case 4:
						/* TODO (#1#): excluir */
						break;
					
				}
				
			case 3:
				/* TODO (#2#): terminar os produtos e colar aki como clientes */
				break;
				
			case 4:
				/* TODO (#2#): terminar os produtos e colar aki como fornecedores */
				break;
				
			case 5:
				/* TODO (#2#): terminar os produtos e colar aki como parceiros */
				break;
				
			case 6: //Laura
				cout << "==============> Ajuda <============== \n\n";
	
				cout << "=> Ao abrir o sistema digite a sua senha e pressione a tecla ENTRER \n";
				cout << "=> Para voltar na página anterior digite 9 \n";
				cout << "=> Para encerrar o sistema digite 0 \n";
				cout << "=> Para ir até a página desejada basta digitar o numero informado \n";
				cout << "=> Ao digitar um número que não corresponde a nenhuma opção aparecerá OPÇÃO INVÁLIDA \n\n";
	
				cout << " 9 | Voltar ao menu principal  0 | Encerrar o programa \n" << "=> ";
				cin >> l;

				break;
				
			case 7: //João e Emanuelly
				cout << "==========  SOBRE  ==========="<<"\n\n"; 
	 
				cout << " O Sistema SOS foi desenvolvido por Erick Cristiano, Laura Costa, João Victor Freitas e Emanuely Gonçalves, cujo uma nova versão atualizada 1.0.2022 \n";
				cout << "Esse sistema foi criado para tornar a tomada de decisões mais eficiente e produtiva";
			    cout <<	"Ele reúne as informações de clientes, produtos, fornecedores e parceiros em um só lugar afim de facilitar a organização da empresa.";
				
				cout << " 9 | Voltar ao menu principal  0 | Encerrar o programa \n" << "=> ";
				cin >> l;
				break;
			
 		}
			
	}
	
	
	
}
