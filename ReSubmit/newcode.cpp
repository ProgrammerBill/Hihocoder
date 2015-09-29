#include <iostream>
#include <vector>
#define MAX 100


using namespace std;

int calculate(vector<int> dates,int M);
int useM(vector<int> dates,int idx, int num);

int main(void)
{
	int T;
	int N,M;
	int date;
	vector<int> dates;

	for(cin>>T;T--;){
		cin>>N;
		cin>>M;
		dates.clear();
		for(int i=0;i<N;i++){
			cin>>date;
			dates.push_back(date);
		}
		cout<<calculate(dates,M)<<endl;
	}
	return 0;
}

int useM(vector<int> dates,int idx,int num){
	if(idx == 0){
		return (dates[idx+num] - 1);
	}else if((idx+num-1) == dates.size()-1){
		return (MAX - dates[dates.size()-2]);
	}else{
		return (dates[idx+num] - dates[idx-1]-1);
	}
	return 0;
}

int calculate(vector<int> dates,int M){
	int count = 0;
	int temp;
	int end;

	if(M>=dates.size()) return MAX;
	else end = dates.size() - M;
	for(int i=0;i<end;i++){
		temp = useM(dates,i,M);
		if(temp>count){
			count = temp;
		}
	}
	return count;
}

