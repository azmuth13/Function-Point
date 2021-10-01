#include <iostream> 
#include <bits/stdc++.h>

using namespace std; 


// Driver Code
struct  parameters
{
	string ask;
	int lowCount, averageCount, highCount;
	
	vector <int> weightingFactors;
};


int main() 
{   

	vector < parameters > vs(5);

	vs[0].ask = "External Inputs (EI)";
	vs[1].ask = "External Output (EO)";
	vs[2].ask = "External Inquiries (EQ)";
	vs[3].ask = "Internal logical files (ILF)";
	vs[4].ask = "External interface files (EIF)";

	vector <vector <int> > weights(5);

	weights[0] = {3, 4, 6};
	weights[1] = {4, 5, 7};
	weights[2] = {3, 4, 6};
	weights[3] = {7, 10, 15};
	weights[4] = {5, 7, 10};


	for(int i = 0; i < 5; i++)
	{
		cout<<vs[i].ask<<endl;
		cout<<"Enter number of Parameters with low complexity\n";
		cin >> vs[i].lowCount;

		cout<<"Enter number of Parameters with average complexity\n";
		cin >> vs[i].averageCount;

		cout<<"Enter number of Parameters with high complexity\n";
		cin >> vs[i].highCount;

		vs[i].weightingFactors = weights[i];
		cout <<"\n";
	}

	int UFP = 0;


	for(int i = 0; i < 5; i++)
	{
		int tempSum = 0;

		tempSum += vs[i].lowCount * vs[i].weightingFactors[0];
		tempSum += vs[i].averageCount * vs[i].weightingFactors[1];
		tempSum += vs[i].highCount * vs[i].weightingFactors[2];

		UFP += tempSum;
	}


	int sumFi = 0;

	cout<< "Enter the 14 rating factors. (rating between (0-5) both inclusive)\n";


	for(int i = 0; i < 14; i++)
	{
		int x;
		cin >> x;

		sumFi += x;
	}

	double CAF = 0.65 + (0.01 * sumFi);
	double FP = UFP * CAF;

	
	cout <<"Unadjusted Function Point Count = "<< UFP <<endl;
	cout <<"Function point Count = "<< FP <<endl;
	return 0; 
	
   	
}

