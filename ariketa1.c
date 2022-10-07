#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>.


int main(int argc, char* argv[])
{
using namespace std;

if(argc!=3)
{
cout << "Usage: " << argv[0] << " [file] [max group size]" << endl;
return 0;
}

for(int i=0; i<atoi(argv[2]); i++)
{
int c;
map<string,int> freq;
ifstream file(argv[1]);
string group;
while( (c=file.get()) && !file.eof() )
{
if(isspace(c))
continue;
group += string(1,c);

if(group.size()>=i+1)
freq[group.substr(group.size()-i-1, i+1)]++;
}

cout << endl << "-- FREQ SIZE " << i+1 << " --" << endl;
int count = 0;
map<string,int>::iterator it = freq.begin();    
for(;it!=freq.end(); it++)
{
if((*it).second>1)
{
count ++;

cout << (*it).first << ": " << (*it).second << "\t";

if(count%6==0)
cout << endl;
}
}
cout << endl;
}
}
