#include<bits/stdc++.h>
using namespace std;

vector<string> input1;

int main(int argv,char** argc)
{
	fstream input;
	fstream output;
	queue<string> q;
	input.open("input.csv",ios::in);	//creating object to read the file
	output.open("output.csv",ios::out);// cretaing object to write to a file
	while(!input.eof())
	{
		string cha,chb;
		getline(input,cha);
		stringstream word(cha);	//reading a line from file
		string temp;
		while(getline(word,chb,','))	
		{
			temp.push_back(chb[0]);	//creating one word from one line of csv
		}		
			input1.push_back(temp);	// pushing that word in a vector
	}
//		int n=input1.size();
//		cout<<n<<endl;
//		for(int i=0;i<input1.size();i++)
//		{
//			cout<<input1[i]<<" ";
//		}
//		cout<<endl;
		for(int i=0;i<input1.size();i++)
		{
			if(i==0)
			{
				for(int j=0;j<input1[i].size();j++)
				{
					string sa;
					sa.push_back(input1[i][j]);
						// adding the fist elements in the queue
					// which will be further used to create permutation
					q.push(sa);
				}
			}
			else
			{
				queue<string> q1;
				while(!q.empty())
				{
					string sb=q.front();
					for(int j=0;j<input1[i].size();j++)
					{
						sb.push_back(input1[i][j]);//creating the permutation by adding
						//next line characters from queue
						q1.push(sb);//pushing in the queue the newly made permutations
						sb.pop_back();//coming back to previous state for other characters
					}
					q.pop();//now next element will make the permutation
				}
				q=q1;//swapping the queue as q1 is now having the new permutations
			}
		}
	
//	cout<<q.size();
//	/*
	while(!q.empty())
	{
//		cout<<q.front()<<", ";
		
		output<<q.front();// pushing all the elements of the queue in the
		//output csv file.
		q.pop();
//		break;
		
	}
//	*/
	
	
	return 0;
}
