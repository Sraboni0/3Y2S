#include<bits/stdc++.h>
using namespace std;

int findLRU(int time[], int n){

	int i, minimum = time[0], pos = 0;

	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}

	return pos;
}

int main()
{
    int no_of_frames, no_of_pages;
	int frames[10], pages[30], counter = 0, time[10];
	int flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &no_of_frames);

	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);

	printf("Enter Pages: ");

    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }

	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }

    for (int i = 0; i < no_of_pages; ++i)
    {
    	 flag1=flag2=0;
    	 for (int j = 0; j <no_of_frames ; ++j)
    	 {
    	 	 if(frames[j]==pages[i]){
    	 	 	counter++;
    	 	 	time[j]=counter;
    	 	 	flag1=flag2=1;
    	 	 	break;
    	 	 }
    	 }
    	 if(flag1==0){
    	 	for (int j = 0; j < no_of_frames; ++j)
    	 	{
    	 		if(frames[j]== -1){
    	 			counter++;
    	 			faults++;
    	 			frames[j]=pages[i];
    	 			time[j]=counter;
    	 			flag2=1;
    	 			break;
    	 		}
    	 	}
    	}
    	if(flag2==0){
    		pos = findLRU(time,no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}
    	cout<<endl;
		for (int l = 0; l < no_of_frames; ++l)
		{
			cout<<frames[l];
		}
    }
	printf("\n\nTotal Page Faults = %d", faults);

    return 0;
}
