#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
// --------------------------------------------------------------------------------------------------------------
const int n = 9;
// --------------------------------------------------------------------------------------------------------------
void menu();
void frist_line();
void main_line();
void copy_row(int a[][n],int b[n],int n);
void main_column(int temp[n]);
void clear_array(int a[][n],int );
void second_line();
void end_line();
void Table(int sud[][n],int color[][n]);
void input2(int a[][n],int color[][n]);	
bool is_between(int n ,int i , int j);
void create_Puzzle();
void print(int a[][9]);
void colored_custom(int sud[][n],int color[][n]);
bool is_end(int sud[][n],int color[][n]);
void input1(int a[][n]);
void change_color(int a);
int counter(int sud[][n]);
void write_text(int a[][n]);
//-----------------------------------------------------------------------------
void load_text(int a[][n],string text);
int search_int_in_array(int a[n][n],int n);
void check(int sud[][n],int color[][n]);
bool is_repeated(int a[n][n],int n,int row,int column);
void update(int sud[][n],int color[][n],int n);
void Solve_Puzzle();
//-----------------------------------------------------------------------------
void Solve_Puzzle_Automatically();
bool find_free(int *x,int *y,int sud[][n]);
bool solve(int sud[][n],int color[][n]);
//-----------------------------------------------------------------------------
char c1 = (char)177;
char s1 = (char)186;  
char s2 = (char)205;	
char s3 = (char)201;
char s4 = (char)203;
char s5 = (char)204;
char s6 = (char)206;
char s8 = (char)196;
char s9 = (char)187;
char s11 = (char)188;
char s10 = (char)200;
char s12 = (char)202;
char s13 = (char)185;
string space3 = "   ";

HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);
// --------------------------------------------------------------------------------------------------------------
int main(){	
	menu();
	return 0;
}

void menu(){
	change_color(6);
	cout << "---Wellcome to Game---" << endl<< endl;
	change_color(15);
	
	
	change_color(9);
	cout << "Choose from the following options:"<< endl<< endl;
	change_color(15);
	
	int number_user = 0;
	cout << "1. Create Puzzle " <<endl;
	cout << "2. Solve Puzzle " <<endl;
	cout << "3. Solve Automatically" << endl;
	cout << "4. Exit" <<endl;

	
	cin >> number_user;
	
	switch(number_user){
		case(1):{
			create_Puzzle();
			break;
		}
		case(2):{
			Solve_Puzzle();
			break;
		}
		case(3):{
			Solve_Puzzle_Automatically();
			break;
		}
		case(4):{
			break;
		}
		default:{
			break;
		}
	}
}

void create_Puzzle(){
	int sud[n][n];
	clear_array(sud,0);
	input1(sud);

	write_text(sud);
	cout << "---The puzzle was saved successfull---" << endl;
}

void Solve_Puzzle(){
	int sud[n][n],color[n][n];
	clear_array(sud,0);
	system("CLS");
	string Address = "D:\\decktop\\mabani_project\\output.txt";
	
	change_color(6);
	cout << "---Solve Sudoku---" << endl << endl;
	change_color(15);
	
	cout << "Enter the Sudoku puzzle address as in the example below:" << endl;
	change_color(9);
	cout << Address << endl;
	change_color(15);
	cin >> Address ;
	
	
	load_text(sud,Address);
	input2(sud,color);
	check(sud,color);
			
}

void Solve_Puzzle_Automatically(){
	int sud[n][n],color[n][n];
	clear_array(sud,0);
	clear_array(color,6);
	
	system("CLS");
	string Address = "D:\\decktop\\mabani_project\\output.txt";
	
	change_color(6);
	cout << "---Solve Automatically Sudoku---" << endl << endl;
	change_color(15);
	
	cout << "Enter the Sudoku puzzle address as in the example below:" << endl;
	change_color(9);
	cout << Address << endl;
	change_color(15);
	cin >> Address ;
	
	
	load_text(sud,Address);
	Table(sud,color);
	cout << "------------------" << endl;
	change_color(9);
	cout << "for start solving enter 1" << endl;
	change_color(15);
	int n = 0;
	while(n!=1){
		cin >> n;
	}
	
	
	if(solve(sud,color)){
		Table(sud,color);
	}
	else{
		cout << "this sudoco is not true!" << endl;
	}
			
}
// --------------------------------------------------------------------------------------------------------------
bool solve(int sud[][n],int color[][n]){
	int row,column;
	
	if(!find_free(&row,&column,sud)){
		return true	;	
	}
	
	
	for(int i=1;i<=n;i++){
		if(!is_repeated(sud,i,row,column)){
			sud[row][column] = i;
			color[row][column] = 10;
			if(solve(sud,color)){
				return true;
			}
			sud[row][column] = 0;	
			color[row][column] = 15;		
		}
	}
	return false;
}

bool find_free(int *x,int *y,int sud[][n]){
	for(int i = 0;i<n;i++){
		for(int j = 0; j < n ; j++){
			if(sud[i][j]==0){
				*x = i;
				*y = j;
				return true;			
				}
		}
	}
	return false;
}
// --------------------------------------------------------------------------------------------------------------
void change_color(int a){
	SetConsoleTextAttribute(Color, a);
}

bool is_end1(int color[][n]){
	bool end = false;
	for(int i = 0 ; i < n ;i++){
		for(int j = 0 ; j < n ; j++){
			if(color[i][j] == 4){
				end = true;
			}
		}
	}
	return end;
}

int counter(int sud[][n]){
	int count = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j<n;j++){
			if (sud[i][j] != 0){	
				count++;
			}
		}
	}
	return count;
}

void input1(int a[][n]){
	int color[n][n];
	int row,column,value;
	bool adame = true,end;
	int number;
	int count = 0;
	clear_array(color,15);
	colored_custom(a,color);
	Table(a,color);
	
	
	cout << "-----------Create Sod-----------"<<endl;
	change_color(3);
	cout << "-You must enter at least 17 values for Sudoku to be solvable" << endl;
	cout << "-after enter values chosen 2. program has saved this Sudoku Next to the cpp file" << endl;
	cout << "-If you do not place the numbers correctly according to sudoku rules, they will turn red. " << endl;
	cout << "-Otherwise they will turn green" << endl;
	change_color(15);
	cout << "-------------" <<endl;
	do{
		row = 0;
		column = 0;
		value = 0;
		count = counter(a)+1;
		
		
		while(!is_between(row,n+1,0)){
			cout << "insert row :  " ;
			cin >> row;
		}
		while(!is_between(column,n+1,0)){
			cout << "insert column :  " ;
			cin >> column;
		}
		while(!is_between(value,n+1,0)){
			cout << "insert value :  ";
			cin >> value;
		}
		
		
		row--;
		column--;
		if(color[row][column]!=6){
			if(is_repeated(a,value,row,column)){
				a[row][column] = value;
				color[row][column] = 4;
			}
			else{		
				a[row][column] = value;
				color[row][column] = 10;
			}
		}
		else{		
					
				cout << "Can't Change Customs!" << endl;
			}
		update(a,color,10);
		Table(a,color);
		
		
		end = is_end1(color);
		
		if(count>17){
			change_color(4);
			cout << "Enter more numbers to make the puzzle solvable" << endl;
			change_color(15);
		}
		if(end){
			change_color(4);
			cout << "It is against the rules of Sudoku" << endl;
			change_color(15);
		}
		
		
		cout << "1.add "<< count <<"th number" << endl;
		cout << "2.end" << endl;
		cin >> number;
		
		if((number == 2) && (count>17) && !end){
				adame = false;
			}
		
		while((number != 1)&&(number != 2)){
			if ((number != 1) && (number != 2)){
				change_color(4);
				cout << "enter 1 or 2 for chose action" << endl;
				change_color(15);
				cout << "1.add "<< count <<"th number" << endl;
				cout << "2.end" << endl;
				cin >> number;
			}		
		}
		
		
	}while(adame);
	
	
}

void write_text(int a[][n]){
	
	ofstream outputFile("soudoco.txt", ios::out);
	if( !outputFile)
 	{
 	cerr << "some thing wrong during opening file!" << endl;
 	exit(1);
 	}	 
	for(int i =0;i<n;i++){
		for(int j = 0 ;j<n;j++){
			outputFile << a[i][j] << endl;
		}
	}	
}
// --------------------------------------------------------------------------------------------------------------
void check(int sud[][n],int color[][n]){
	update(sud,color,10);
	Table(sud,color);
	
	int count_false = search_int_in_array(color,4);
	
	cout << "---End Game---" << endl;
	if (count_false == 0){
		change_color(6);
		cout << "You won!" <<endl;
		change_color(15);
	}
	else{
		change_color(4);
		cout << "Game Over!" <<endl;
		change_color(15);
	}
	
	
	
}

int search_int_in_array(int a[n][n],int n){
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(a[i][j] == n){
				count++;
			}
		}
	}
	
	return count;
}

void load_text(int a[][n],string text){
	ifstream inputFile;
	inputFile.open(text.c_str());
	int temp;
	
	for(int i =0;i<n;i++){
		for(int j = 0 ;j<n;j++){
			inputFile >> temp;
			a[i][j] = temp;
		}
	}
	
	inputFile.close() ;
}

void print(int a[][n]){
	for(int i = 0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << a[i][j] << " " ;
		}
		cout << endl;
	}
}

bool is_repeated(int a[n][n],int n,int row,int column){
	bool repeat = false;
	for(int i=0;i<n;i++){
		if((n==a[row][i])&&(i!=column)){
			repeat = true;
		}
	}
	for(int i=0;i<n;i++){
		if((n==a[i][column])&&(i!=row)){
			repeat = true;
		}
	}
	for(int i = row-(row%3) ;i<row+3-(row%3) ; i++){
		for(int j = column-(column%3) ; j<column+3-(column%3)  ; j++){
			if((n==a[i][j])&&!((row==i)&&(column==j))){
				repeat = true;
			}
		}
	}
	return repeat;
}

void frist_line(){
	cout << s3;
	for(int i = 0;i<n;i++){
			for(int h =0;h<3;h++){
				cout << s2 ;
			}
			if(i==8){
				break;
			}
			cout << s4;
		}
	cout << s9 << endl;
	
}

void end_line(){
	cout << s10;
	for(int i = 0;i<9;i++){
			for(int h =0;h<3;h++){
				cout << s2 ;
			}
			if(i==8){
				break;
			}
			cout << s12;
		}
	cout << s11 << endl;
}

void main_line(){
	string output = "";
	cout << s5;
	for(int i = 0;i<n;i++){
			for(int h =0;h<3;h++){
				output += s2 ;
			}
			if(i==8){
				break;
			}
			output += s6;
		}
	cout << output << s13 << endl;
}

void second_line(){
	string output = "";
	cout << s5;
	for(int i = 0;i<n;i++){
			for(int h =0;h<3;h++){
				output += s8 ;
			}
			if(i==8){
				break;
			}
			output += s6;
		}
	cout << output << s13 << endl;
}

void copy_row(int a[][n],int b[n],int n){
	for(int i=0;i<9;i++){
		b[i] = a[n][i];
	}
}

void colored_custom(int sud[][9],int color[][9]){
	for(int i = 0;i<9;i++){
		for(int j = 0;j<9;j++){
			if(sud[i][j]!=0){
				color[i][j] = 6;
			}
		}
	}
	
}
	
void main_column(int temp[9],int color[9]){
	for(int i = 0;i<7;i+=3){		

		cout<< s1; 
		if(temp[i]!=0){
			change_color(color[i]);
			cout<< " " << temp[i] << " ";
			change_color(15);
		}		
		else{
			cout<< space3;
		}
		cout<< "|" ;
		if(temp[i+1]!=0){
			change_color(color[i+1]);
			cout<< " " << temp[i+1] << " ";
			change_color(15);
		}		
		else{
			cout<< space3;
		}
		cout<< "|" ;
		if(temp[i+2]!=0){
			change_color(color[i+2]);
			cout<< " " << temp[i+2] << " ";
			change_color(15);
		}		
		else{
			cout<< space3;
		}
	}
	cout << s1 << endl;
}	

void clear_array(int a[][9],int num){
	for(int i = 0;i<9;i++){
		for(int j=0;j<9;j++){
			a[i][j] = num ;	
		}
	}
}

void Table(int sud[][9],int color[][9]){
	int temp[9];
	int temp_color[9];
	system("CLS");
	frist_line();
	int n = 0;
	for(int i =0;i<3;i++){
		for(int j=0;j<2;j++){
			copy_row(sud,temp,n);
			copy_row(color,temp_color,n);
			main_column(temp,temp_color);
			n++;
			second_line();	
		}
		copy_row(sud,temp,n);
		copy_row(color,temp_color,n);
		main_column(temp,temp_color);
		n++;
		if(i==2){
			break;
		}
		main_line();
	}
	end_line();
}

bool is_between(int n ,int i , int j){
	bool result=false;
	if((n < i)&&(n > j)){
		result = true;
	}
	return result;
}

bool is_end(int sud[][9],int color[][9]){
	bool end = true;
	for(int i = 0 ; i < 9 ;i++){
		for(int j = 0 ; j < 9 ; j++){
			if(sud[i][j]==0){
				end = false;
			}
			if(color[i][j] == 4){
				end = false;
			}
		}
	}
	
	return end;
}

void update(int sud[][9],int color[][9],int n){
	
	for(int i = 0 ; i < 9 ;i++){
		for(int j = 0 ; j < 9 ; j++){
			
			if((color[i][j] != 6) &&(sud[i][j]!=0)){
				cout << sud[i][j] << endl;
				if(!is_repeated(sud,sud[i][j],i,j)){
					color[i][j] = n;
				}
				else{
					color[i][j] = 4;
				}
			}
		}
	}
}

void input2(int a[][9],int color[][9]){
	int row,column,value;
	bool adame = true;
	int number;
	bool end;
	clear_array(color,15);
	colored_custom(a,color);
	Table(a,color);
	cout << "--------------------------------"<<endl;
	change_color(6);
	cout << "Golden numbers are the default numbers in the table" <<endl;
	change_color(15);
	cout << "White numbers are user input" <<endl<<endl;
	change_color(3);
	cout << "Enter values for all empty cells and select the second option at the end to correct the sudoku puzzle." <<endl<<endl;
	change_color(15);
	cout << "-----------Start Game-----------"<<endl;
	do{
		row = 0;
		column = 0;
		value = 0;
		
		
		
		while(!is_between(row,n+1,0)){
			cout << "insert row :  " ;
			cin >> row;
		}
		while(!is_between(column,n+1,0)){
			cout << "insert column :  " ;
			cin >> column;
		}
		while(!is_between(value,n+1,0)){
			cout << "insert value :  ";
			cin >> value;
		}
		
		
		row--;
		column--;
		if(color[row][column]!=6){
			a[row][column] = value;
			Table(a,color);
		}
		else{	
			Table(a,color);
			change_color(4);	
			cout << "-Can't Change Customs!" << endl;
			change_color(15);
		}
		
		
		end = is_end(a,color);
		cout << "1.add another number" << endl;
		cout << "2.done" << endl;
		cin >> number;
		if(number == 2){
			if(end){
				adame = false;
			}
		}
		else if ((n != 1) && (number == 2)){
			cout << "some place is empty" << endl;
		}
		system("CLS");
		Table(a,color);
	}while(adame);
	
	
}
