#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream infile;
    infile.open("80_scores.txt");
    
    int inputNum;
    
    double sum = 0.0;
    int count = 0;
    int min = 0;
    int max = 0;
    double average = 0.0;
    
    if(!infile)
    {
        cout<<"ERROR in opening file"<<endl;
        return 1;
    }
    
    while(!infile.eof())
    {
        infile>>inputNum;
        
        if(inputNum > 0 && inputNum < 100)
        {
            if(count == 0)
            {
                min = inputNum;
                max = inputNum;
            }
            
            if(max < inputNum)
            {
                max = inputNum;
            }
            
            if(min > inputNum)
            {
                min = inputNum;
            }
            
            sum += inputNum;
            count++;
        }
    }
    
    if(count != 0)
    {
        average = sum / count;
    }
    
    cout<<"Statistics: "<<endl;
    cout<<"\tmin: "<<min<<endl;
    cout<<"\tmax: "<<max<<endl;
    cout<<"\taverage: "<<average<<endl;
    
    infile.close();
    return 0;
}