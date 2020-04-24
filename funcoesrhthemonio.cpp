bool buscarFuncionario (int codigo)
{
	bool achei = false;
	
	/*le linha por linha do vetor vCodigos*/
	for (linha = 0; linha < vCodigos.size(); linha++)
	{
		/*verifica se determina linha
		contem o c�digo passado por parametro 
		(pois o for so trabalha com parametros hehe)*/
		if (vCodigos[linha] == codigo)
		{
			/* se SIM, ent�o muda o valor da variavel "achei"
			para true e para a pesquisa*/
			achei = true;
			break;
		}
	}
	/* retorna se achou ou n�o
	o codigo passado como parametro*/
	return achei;
}

	/*CRUD = Create (cadastrar), 
    retrieve (consultar), 
    update (alterar), 
    delete (apagar)*/

/*fun��o para entrada de dados*/
void entrarDados()
{
	fflush(stdin);
	cout << "Nome: "; getline(cin, nome);
	cout << "Cargo: "; getline(cin, cargo);
	cout << "Setor: "; getline(cin, setor);
	cout << "Salario: "; getline(cin, salario);
}

void createFuncionario()
{
	/*grava cada variavel em seu respectivo vetor*/
	vCodigos.push_back(cod);
	vNomes.push_back(nome);
	vCargos.push_back(cargo);
	vSetores.push_back(setor);	
    vSalarios.push_back(salario);	
	vAdmissao.push_back(false);
}

void retrieveFuncionario()
{
	/*consulta os cara l� nos vetores*/
	cout << "Funcion�rio encontrado! " << endl;
	cout << "Nome: " << vNomes[linha] << endl;
	cout << "Cargo: " << vCargos[linha] << endl;
	cout << "Setor: " << vSetores[linha] << endl;
    cout << "Salario: " << vSalarios[linha] << endl;
}

void updateFuncionario()
{
	/*altera os dados na tabela (vetores)*/
	vNomes[linha] = nome;
	vCargos[linha] = cargo;
	vSetores[linha] = setor;
    vSalarios[linha] = salario;
}

void deleteFuncionario()
{
	/*deleta os dados do funcionario*/
	vCodigos.erase(vCodigos.begin()+linha);
	vNomes.erase(vNomes.begin()+linha);
	vCargos.erase(vCargos.begin()+linha);
	vSetores.erase(vSetores.begin()+linha);
	vSalarios.erase(vSalarios.begin()+linha);
	vAdmissao.erase(vAdmissao.begin()+linha);	
}

/*colocando o crud pra funfar*/

void CRUDrh()
{
	
	string resp;
	bool achou;		
	
	system ("cls");
	cout << " -=-=-= R.H. THE MONIO =-=-=-" << endl;
	
	/*pergunta o codigo do funcionario*/
	cout << "C�digo :";
	cin >> cod;
	
	/*procura pelo codigo informado na tabela de funcionario (vetor vCodigos)*/
	achou = buscarFuncionario (cod);
	
	
	/*se achou o funcionario, mostra os dados*/
	if (achou == true)
	{
		retrieveFuncionario();
		
		cout << "Voce deseja A-Alterar, E-Excluir ou V-Voltar?";
		cin >> resp;
		
		/*o usuario deseja excluir o funcionario do cadastro*/
		if (resp == "e" || resp == "E")
		{
			/*solicita confirma��o do usuario para apagar o registro*/
			cout << "Confirma exclusão (S/N) :"; cin >> resp;
			
			/*se o usuario confirmou a exclus�o vai deletar tudo.. tururuuu*/
			if (resp == "s" || resp == "S")
			{
				deleteFuncionario();	
			}			
		}
		
		/*o usuario deseja alterar os dados do cadastro*/
		else if (resp == "a" || resp == "A")
		{
			/*solicita a entrada dos novos dados*/
			entrarDados();
						
			/*solicita confirma��o para altera��o dos dados*/
			cout << " Confirma altera��o (S/N) :"; cin >> resp;
			
			/*o usuario confirmou a altera��o*/
			if (resp == "s" || resp == "S")
			{
				updateFuncionario();
			} 			
		}
	}
	
	/*se n�o achou o cara, pergunta se quer cadastrar um novo cara*/
	else
	{
		cout << "Codigo N�O encontrado! Deseja cadastrar funcion�rio? (S/N) :";
		cin >> resp;
		
		/*se ele quer*/
		if (resp == "s" || resp == "S")
		{
			/*solicita a entrada dos novos dados*/
			entrarDados();		
		
			/*pergunta se � isso memo*/
			cout  << "Confirma o cadastro do funcion�rio (S/N) : ";
			cin >> resp;
		
			/*se confirma o usuario confirma o cadastro, coloca o novo cabra dentro dos vetores*/
			if (resp == "s" || resp == "S")
			{
				createFuncionario();
			}				
		}			
	}	
}

void listarFuncionario()
{
	string demitido;
	
	system ("cls");
	cout << "-=-= Listagem de funcion�rio =-=-" << endl;
	
	cout << "Cod" << "\t\t"
		 << "Nome" << "\t\t"
		 << "Cargo" << "\t\t"
		 << "Setor" << "\t\t"
         << "Salario" << "\t\t"
		 << "Demitido" << endl;
	
	for (linha=0; linha<vCodigos.size(); linha++)
	{
		demitido = "nao";
		
		if (vAdmissao[linha] == true) demitido = "sim";
		
		cout << vCodigos[linha] << "\t\t"
			 << vNomes[linha] << "\t\t"
			 << vCargos[linha] << "\t\t"
			 << vSetores[linha] << "\t\t"
             << vSalarios[linha] << "\t\t"
			 << demitido << endl;			 
		
	}	
	system ("pause");
}

void demitirFuncionario()
{
	string resp;
	
	system ("cls");
	
	cout << "-=-= Demiss�o de funcion�rio =-=-"  << endl;
	cout << "Informe os dados do funcion�rio" << endl;
	cout << "C�digo do funcion�rio: "; cin >> cod;
	
	if (buscarFuncionario (cod))
	{
		cout << "Nome: " << vNomes[linha] << endl;

		if (vAdmissao[linha] == true)
		{
			/*nao da pra demitir duas vezes n� champs*/
			cout << "O Funcion�rio j� est� demitido!" << endl;
			
		}
		else
		{			
			cout << "Confirma a demiss�o? (S/N) :";
			cin >> resp;
			
			if (resp == "s" || resp == "S")
			{
				vAdmissao[linha] = true;
			}
		}
	}
	else
	{
		cout << "Funcion�rio n�o encontrado!" << endl;
	}
	system ("pause");
}

void readmitirFuncionario()
{
	string resp;
	
	system ("cls");
	
	cout << "-=-= Readmiss�o de funcion�rio =-=-" << endl;
	cout << "C�digo do funcion�rio: "; cin >> cod;
	
	if(buscarFuncionario(cod))
	{
		cout << "Nome: " << vNomes[linha] << endl;
		
		if(vAdmissao[linha] == true)
		{
			cout << "Confirma readmiss�o (S/N) :"; cin >> resp;
			
			if (resp == "s" || resp == "S")
			{
				vAdmissao[linha] = false;
			}
		}
		else
		{
			cout << "Este funcion�rio não foi demitido!" << endl;
		}
	}
	else
	{
		cout << "Funcion�rioo n�o cadastrado!" << endl;
	}
	system("pause");
}
