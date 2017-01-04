#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>

using namespace std;

string remove_number(string);
string repalce_dash(string);
string remove_space(string);
string remove_Article(string);
string arranging_names(string);
string remove_no_author(string);

int main(){

ifstream cdfile;
ofstream projectfile;
string filename;

cout<<"Please enter your file name with format \"E:/mac125/project/cdfile.txt\""<<endl;
cout<<"Or Enter the file name (cdfile.txt) if it is in same folder to your program."<<endl;
cin>>filename;
vector <string> my_vec;
vector <string>::iterator it=my_vec.begin();
cdfile.open(filename);


	if(cdfile.fail()){
		cout<<"The file could not be opened."<<endl;
		exit(0);
	}
projectfile.open("projectfile.txt");


	if(projectfile.fail()){
		cout<<"The file could not be opened."<<endl;
		exit(2);
	}

while(!cdfile.eof())
	{
		string temp;

		getline(cdfile,temp);
			//a. replacing the numbers and other symbols
			temp=remove_number(temp);
			//b. replacing the multiple spaces

			temp=remove_space(temp);
			//c. and d. replacing "-" except the last one
			temp=repalce_dash(temp);

			//e. replacing the 'A' , 'An' and 'The'
			temp=remove_Article(temp);

			//moving composers names to the front and title to the back
				int index;
				index=temp.find("- ");
				string title=temp.substr(0,index);
				string names=temp.substr(index+2);
				temp=names+" - "+title;
				//remove  no author
				names=remove_no_author(names);
				names=arranging_names(names);
				temp=names+ " - "+ title;



my_vec.push_back(temp);


}
/*
 * tried to avoid the repeating authors
int i,j,k;
string name_title[100];
for(i=0;i<=num;i++){


	for(j=i+1;j<=num;j++){

		if(name[i]==name[j]&&(i<j)){
			k=j;
		}
	}
	if(i==k){
			i=k+1;}
			my_vec.push_back(temp_name[i]);

}
*/
//writing the title for the new file
projectfile<<"The new file after changing the original file "<<filename<<endl;
projectfile<<"\n";

cout<<"The result of this project at end: "<<endl;
//sort the vector and display then write everything back to the output file
for (int i=0;i<my_vec.capacity();i++){
	cout<<my_vec.at(i)<<endl;
	sort(my_vec.begin(),my_vec.end());

projectfile<<my_vec.at(i)<<endl;
}
//}
cdfile.close();
projectfile.close();
return 0;
}

//Function to remove the numbers and symbols
string remove_number(string A){
int i=0;
	while(!isalpha(A.at(i))){
				i++;}
	A=A.substr(i);
	return A;
}
//Function to removing the "-" except the last one
string repalce_dash(string A){
int index;
	index=A.find("-");
		while(index>=0){
		string temp1=A.substr(index+1);
		int newindex=temp1.find("-");
		if(newindex>=0){
			A.replace(index,1," ");
			index=index+newindex+1;
		}
		else{
			break;

		}

		}
	return A;
}
//Function to replace multiple white space with one space
string remove_space(string A){
	int index;
	index=A.find("  ");

	if(index>=0){
			A.replace(index,2," ");
			index=index+1;
		}
	return A;
}
//Function to replacing the article 'A' , 'An' and 'The'
string remove_Article(string A){
	int index;
	index=A.find("A ");
					if(index>=0){
						A=A.substr(index+2);
					}
	index=A.find("An ");
					if(index>=0){
						A=A.substr(index+3);
					}
	index=A.find("The ");
					if(index>=0){
						A=A.substr(index+4);
					}
	return A;
}
//moving the names to the front and title to the last
string arranging_names(string A){
	int index;
	//changing only for author listed
	if(A!="no author listed"){
		index=A.find("and");
		if(index>=0){
	return A;
		}
		else{
			int index=A.find(" ");{
				if(index>=0){
				string first_name=A.substr(0,index);
				string temp=A.substr(index+1);
					int new_index=temp.find(" ");
					if(new_index>=0){

					string middle_name=temp.substr(0,new_index);
					string last_name=temp.substr(new_index+1);
					A=last_name+" "+first_name+" "+middle_name;
					//cout<<" l: "<<last_name<<" f: "<<first_name<<" m: "<<middle_name<<endl;
											}
					else{
					string first_name=A.substr(0,index);
					string last_name=A.substr(index+1);
					A=last_name+" "+first_name;
										}
						}
			}
		return A;
		}
	}
	return A;

}
string remove_no_author(string A){
	int index;
	index=A.find("no author listed");

	if(index<0){
			return A;
		}
}
