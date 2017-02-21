#include <iostream>
using namespace std;

int main()
{
	int q[8], c = 0;
	int r, i, j, count = 0;
	q[0] = 0;
	
	nc: c++;
		if(c==8) goto Print;
		q[c] = -1;
	
	nr:q[c]++;
		if(q[c]== 8) goto backTrack;
	    for(i=0;i<c;i++){
    	    if((q[i]==q[c])||(c-i==abs(q[c]-q[i]))) goto nr;
    	}
		goto nc;
		
	//row test
	for(i=0; i<c; i++)
		if(q[i] == q[c]) goto nr;
	
	//up/down diagonal test
	for(i=0; i<c;i++)
		if(((c-i) == (q[c] - q[i])) or (c-i) == (q[i] - q[c])) goto nr;
	
	//backtrack
	backTrack:
		c--;
		if(c==-1) return 0;
		goto nr;
		
	//print
	Print: for(i=0;i<8;i++){
    	cout << q[i] << " ";
    }
    cout<<endl;
    
    ++count;
    cout << "Solution Number: " << count <<endl;
    goto backTrack;
    
    return 0;
}
