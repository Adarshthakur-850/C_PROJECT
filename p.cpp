#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next;
};
node* head = NULL;
node* last = NULL;
int choice = 0, ch =0;
void insert_at_beg(int data){
	node *newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		last = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
}

void insert_at_end(int data){
	node *newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	if(head == NULL){
		head = last = newNode;
	}
	else{
		last->next = newNode;
		last = newNode;
	}
}

void insert_at_pos(int data,int pos){
	node *newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	node *temp = head;
	while(temp != NULL && pos-- > 1){
		temp = temp->next;
	}
	if(temp == NULL){
		if(head == NULL){
			head = last = newNode;
		}
		else{
			last->next = newNode;
			last = newNode;
		}
	}
	else{
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void delete_at_beg(){
	if(head == NULL){
		cout << "Empty List\n";
	}
	else{
		head = head->next;
	}
}
void delete_at_end(){
	node *temp = head;
	while(temp != NULL && temp->next != last){
		temp = temp->next;
	}
	temp->next = NULL;
	last = temp;
}
void delete_at_pos(int pos){
	if(head == NULL){
		cout << "Empty List\n";
		return ;
	}
	node *temp = head,*temp1 = NULL;
	while(temp != NULL && temp->next != NULL && pos-- > 1){
		temp1 = temp;
		temp = temp->next;
	}
	if(temp1 == NULL){
		head = head->next;
	}
	else{
		temp1->next = temp->next;
	}
}
void display_middle(){
	node *slow = head,*fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	if(slow == NULL){
		cout << "Empty List\n";
	}
	else{
		cout << "Middle element " << slow->data << "\n";
	}
}

void display_list(){
	node *temp = head;
	cout << "Linked List \n";
	while(temp != NULL){
		cout << temp->data << "  ";
		temp = temp->next;
	}
}


void linked_list_operation(){
	do{
	cout << "\nSelect any of the below choices : \n";
	cout << "1.Insertion At Beg\n2. Insertion At End\n3.Insertion At Position\n4.Deletion At Beg\n5.Deletion At End\n6. Deletion At Position\n7.Find Middle Element\n";
	cout << "8. Display Linked List\n 0.Exit\n";
	cin >> ch;
	int data =0,pos =0;
	if(ch ==1 || ch == 2 || ch ==3){
		cout << "Enter data to insert\n";
		cin >> data;
		if(ch ==3){
			cout << "Enter position to insert\n";
			cin >> pos;
			cout  << "\nPlease Note that if position is greater than size of linked list, element will be inserted at end of linked list";
		}
	}
	else if(ch == 6){
		cout << "Enter position to delete \n";
		cin >> pos;
		cout << "Please Note that if position is greater than size of linked list, element will be deleted at end of linked list";
	}
	switch(ch){
		case 1 : insert_at_beg(data);break;
		case 2 : insert_at_end(data);break;
		case 3 : insert_at_pos(data,pos);break;
		case 4 : delete_at_beg();break;
		case 5 : delete_at_end();break;
		case 6 : delete_at_pos(pos);break;
		case 7 : display_middle();break;
		case 8 : display_list();break;
		case 0 : return ;
		default : cout << "\n\n* * * * INVALID SELECTION * * * *\n\n";

	}
	}while(ch != 0);
}


void stack_operation(){
	int stack[1];
	int top = -1;
	int size;
	cout << "Enter the size of the stack";
	cin >> size;
	stack[size];
	cout << "1.PUSH\n2.POP\n3.DISPLAY TOP ELEMENT\n4.DISPLAY TOP VALUE\n5.Is STACK EMPTY\n6.Is STACK FULL\n0.EXIT";
	int choice;
	do{
		cout << "\nSelect any of the choices \n";
		cin >> choice;
		switch(choice){
			case 1 : if(top < size-1){
						int data;
						cout << "Enter the data \t";
						cin >> data;
						stack[++top] = data;
//						cout << "top\t"<<top<<"\n";
					}
					else{
						cout << "OVERFLOW !!!\n";
					}break;
			case 2 : if(top != -1){
						cout << "Popped element \t" << stack[top--];

					}
					else{
						cout << "UNDERFLOW !!!\n";
					}break;
			case 3 : if(top == -1){
						cout << "Empty Stack";
					}
					else{
						cout << "Top element \t" << stack[top];
					}break;
			case 4 : cout << "\n Top value  \t" << top;break;
			case 5 : if(top == -1)
						cout << "\nYES";
					else
						cout << "\nNO";
					break;
			case 6 : if(top == size-1)
						cout << "\nYES";
						else
							cout << "\nNO";
						break;
			default : cout << "Invalid selection\n\n";break;
			case 0 : return;
		}
	}while(choice != 0);
}

void queue_operation(){

	int front = -1,rear = -1;
	int queue[1];
	cout << "Enter the size of the Queue\n";
	int size;;
	cin >> size;
	queue[size];
	cout << "1.ENQUEUE\n2.DEQUEUE\n3.FRONT VALUE and REAR VALUE \n4.Is QUEUE EMPTY\n5.Is Queue FULL";
	do{
		int ch= 1;
		cout << "Select any of the choices\n";
		cin >> ch;
		switch(ch){
			case 1 : if(rear== size-1){
						cout << "OVERFLOW !!\n";
					}
					else{
						int data;
						cout << "Enter data\t";
						cin >> data;
						if(front == -1){
							front = rear = 0;
						}
						else{
							rear++;
						}
						queue[rear] = data;
					}break;
			case 2 : if(front == -1 || front > rear){
						cout << "UNDERFLOW !! \n";
					}
					else{
						cout << "Dequeued element \t" << queue[front++]<<"\n";
					}break;
			case 4 : if(front == -1)
						cout << "YES";
					else
					cout << "NO";
					break;
			case 5 : if(front ==0 && rear == size-1)
						cout << "YES";
					else
						cout << "NO";
					break;
			case 3:cout << "Front value\t" << front;
				   cout << "\nRear Value\t"<< rear;break;
			case 0:return ;
			default : cout << "Invalid Selection\n";
		}
	}while(true);
}





void selection_sort(int arr1[],int arr2[],int size)
{
    char ch;
    cout<<"Do you want to perform sorting with new elements (y,n):\t";
    cin>>ch;
    if(ch=='y')
    {
        int n;
    	cout<<"\nEnter the size of the Array:\t";
    	cin>>n;
    	int s_arr[n];

    	for(int i=0;i<n;i++)
    	{
    	    cout<<"Enter element "<<i+1<<" :\t";
    		cin>>s_arr[i];
    	}

    	cout<<"\n\n\t* * * Original Array Elements:* * *\n";

    	for(int i=0;i<n;i++)
    	{
    	    cout<<"\t"<<s_arr[i];
    	}

    	int choice;
    	cout<<"\n\n1.Ascending Order\n";
    	cout<<"\n2.Descending Order\n";

    	cout<<"\nEnter your choice:\t";
    	cin>>choice;


    	if(choice==1)
    	{
    	   for(int i=0;i<n-1;i++)
        	{
        		int min=i;
        		cout<<"\n\nMinumum small selected element is:\t"<<s_arr[min]<<"\n\n";
        		for(int j=i+1;j<n;j++)
        		{
        			if(s_arr[j]<s_arr[min])
        			{
        				min=j;
        				cout<<"\n\nNext updated small element is:\t"<<s_arr[min]<<"\n\n";
        			}

        			if(min!=i)
        			{
        				int temp=s_arr[min];
        				s_arr[min]=s_arr[i];
        				s_arr[i]=temp;
        			}
        		}
        		cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int i=0;i<n;i++)
        		{
        		    cout<<"\t"<<s_arr[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}


        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<n;i++)
        	{
        		cout<<"\t"<<s_arr[i];
        	}
    	}






    	else if(choice==2)
    	{
    	    for(int i=0;i<n-1;i++)
        	{
        		int max=i;
        		cout<<"\n\nMaximum small selected element is:\t"<<s_arr[max]<<"\n\n";
        		for(int j=i+1;j<n;j++)
        		{
        			if(s_arr[j]>s_arr[max])
        			{
        				max=j;
        				cout<<"\n\nNext updated big element is:\t"<<s_arr[max]<<"\n\n";
        			}

        			if(max!=i)
        			{
        				int temp=s_arr[max];
        				s_arr[max]=s_arr[i];
        				s_arr[i]=temp;
        			}
        		}
        		cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int i=0;i<n;i++)
        		{
        		    cout<<"\t"<<s_arr[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}


        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<n;i++)
        	{
        		cout<<"\t"<<s_arr[i];
        	}
    	}
    	else
    	{
    	    cout<<"\n\n* * * INVALID SELECTION * * *\n\n";
    	}

    }
    else if(ch=='n')
    {
        cout<<"\n\n\t* * * Original Array Elements:* * *\n";

    	for(int i=0;i<size;i++)
    	{
    	    cout<<"\t"<<arr2[i];
    	}

    	int choice;
    	cout<<"\n\n1.Ascending Order\n";
    	cout<<"\n2.Descending Order\n";

    	cout<<"\nEnter your choice:\t";
    	cin>>choice;


    	if(choice==1)
    	{
    	   for(int i=0;i<size-1;i++)
        	{
        		int min=i;
        		cout<<"\n\nMinumum small selected element is:\t"<<arr2[min]<<"\n\n";
        		for(int j=i+1;j<size;j++)
        		{
        			if(arr2[j]<arr2[min])
        			{
        				min=j;
        				cout<<"\n\nNext updated small element is:\t"<<arr2[min]<<"\n\n";
        			}

        			if(min!=i)
        			{
        				int temp=arr2[min];
        				arr2[min]=arr2[i];
        				arr2[i]=temp;
        			}
        		}
        		cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int i=0;i<size;i++)
        		{
        		    cout<<"\t"<<arr2[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}


        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}
    	}

    	else if(choice==2)
    	{
    	    for(int i=0;i<size-1;i++)
        	{
        		int max=i;
        		cout<<"\n\nMaximum small selected element is:\t"<<arr2[max]<<"\n\n";
        		for(int j=i+1;j<size;j++)
        		{
        			if(arr2[j]>arr2[max])
        			{
        				max=j;
        				cout<<"\n\nNext updated big element is:\t"<<arr2[max]<<"\n\n";
        			}

        			if(max!=i)
        			{
        				int temp=arr2[max];
        				arr2[max]=arr2[i];
        				arr2[i]=temp;
        			}
        		}
        		cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int i=0;i<size;i++)
        		{
        		    cout<<"\t"<<arr2[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}


        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}
    	}
    	else
    	{
    	    cout<<"\n\n* * * INVALID SELECTION * * *\n\n";
    	}
    }
    else
    {
        cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    }



}

void insertion_sort(int arr1[],int arr2[],int size)
{
    char ch;
    cout<<"Do you want to perform sorting with new elements (y,n):\t";
    cin>>ch;

    if(ch=='y')
    {
        int n;
    	cout<<"\nEnter the size of the Array:\t";
    	cin>>n;

    	int i_arr[n];

    	for(int i=0;i<n;i++)
    	{
    	    cout<<"Enter element "<<i+1<<" :\t";
    		cin>>i_arr[i];
    	}


    	int choice;
    	cout<<"\n\n1.Ascending Order\n";
    	cout<<"\n2.Descending Order\n";

    	cout<<"\nEnter your choice:\t";
    	cin>>choice;

    	if(choice==1)
    	{
    	    cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<n;i++)
            {
                cout<<"\t"<<i_arr[i];
            }

        	for(int i=1;i<n;i++)
        	{
        		int temp=i_arr[i];
        		cout<<"\n\nElement selected is "<<temp<<"\n\n";
        		int j=i-1;
        		while(j>=0&&i_arr[j]>temp)
        		{
        			i_arr[j+1]=i_arr[j];
        			j--;
        		}
        		i_arr[j+1]=temp;

        		cout<<"\n\t\t* * * PASS "<<i<<" * * *\t\t\n";
        		for(int i=0;i<n;i++)
        		{
        		    cout<<"\t"<<i_arr[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";

        	for(int i=0;i<n;i++)
        	{
        		cout<<"\t"<<i_arr[i];
        	}

    	}
    	else if(choice==2)
    	{
    	    cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<n;i++)
            {
                cout<<"\t"<<i_arr[i];
            }

        	for(int i=1;i<n;i++)
        	{
        		int temp=i_arr[i];
        		cout<<"\n\nElement selected is "<<temp<<"\n\n";
        		int j=i-1;
        		while(j>=0&&i_arr[j]<temp)
        		{
        			i_arr[j+1]=i_arr[j];
        			j--;
        		}
        		i_arr[j+1]=temp;

        		cout<<"\n\t\t* * * PASS "<<i<<" * * *\t\t\n";
        		for(int i=0;i<n;i++)
        		{
        		    cout<<"\t"<<i_arr[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";

        	for(int i=0;i<n;i++)
        	{
        		cout<<"\t"<<i_arr[i];
        	}
    	}
    }

    else if(ch=='n')
    {
        cout<<"\n\n\t* * * Original Array Elements:* * *\n";
        for(int i=0;i<size;i++)
        {
            cout<<"\t"<<arr2[i];
        }


        int choice;
    	cout<<"\n\n1.Ascending Order\n";
    	cout<<"\n2.Descending Order\n";

    	cout<<"\nEnter your choice:\t";
    	cin>>choice;


    	if(choice==1)
    	{
    	   for(int i=1;i<size;i++)
        	{
        		int temp=arr2[i];
        		cout<<"\n\nElement selected is "<<temp<<"\n\n";
        		int j=i-1;
        		while(j>=0&&arr2[j]>temp)
        		{
        			arr2[j+1]=arr2[j];
        			j--;
        		}
        		arr2[j+1]=temp;

        		cout<<"\n\t\t* * * PASS "<<i<<" * * *\t\t\n";
        		for(int i=0;i<size;i++)
        		{
        		    cout<<"\t"<<arr2[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\tElements after Sorting:\n";

        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}


        	for(int i=0;i<size;i++)
        	{
        	    arr2[i]=arr1[i];
        	}
    	}
    	else if(choice==2)
    	{
    	    cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<size;i++)
            {
                cout<<"\t"<<arr2[i];
            }

        	for(int i=1;i<size;i++)
        	{
        		int temp=arr2[i];
        		cout<<"\n\nElement selected is "<<temp<<"\n\n";
        		int j=i-1;
        		while(j>=0&&arr2[j]<temp)
        		{
        			arr2[j+1]=arr2[j];
        			j--;
        		}
        		arr2[j+1]=temp;

        		cout<<"\n\t\t* * * PASS "<<i<<" * * *\t\t\n";
        		for(int i=0;i<size;i++)
        		{
        		    cout<<"\t"<<arr2[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";

        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}

    	}
    	else if(choice==2)
    	{
    	    cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<size;i++)
            {
                cout<<"\t"<<arr2[i];
            }

        	for(int i=1;i<size;i++)
        	{
        		int temp=arr2[i];
        		cout<<"\n\nElement selected is "<<temp<<"\n\n";
        		int j=i-1;
        		while(j>=0&&arr2[j]<temp)
        		{
        			arr2[j+1]=arr2[j];
        			j--;
        		}
        		arr2[j+1]=temp;

        		cout<<"\n\t\t* * * PASS "<<i<<" * * *\t\t\n";
        		for(int i=0;i<size;i++)
        		{
        		    cout<<"\t"<<arr2[i];
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";

        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}
    	}
    	else
    	{
    	    cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    	}
    }
    else
    {
        cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    }

}

void bubble_sort(int arr1[],int arr2[],int size)
{
    char ch;
    cout<<"Do you want to perform sorting with new elements (y,n):\t";
    cin>>ch;

    if(ch=='y')
    {
        int n;
    	cout<<"\nEnter the size of the Array:\t";
    	cin>>n;
    	int b_arr[n];

    	for(int i=0;i<n;i++)
    	{
    	    cout<<"Enter element "<<i+1<<" :\t";
    		cin>>b_arr[i];
    	}

    	int choice;
    	cout<<"\n\n1.Ascending Order\n";
    	cout<<"\n2.Descending Order\n";

    	cout<<"\nEnter your choice:\t";
    	cin>>choice;

    	if(choice==1)
    	{
    	    cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<n;i++)
            {
                cout<<"\t"<<b_arr[i];
            }

        	for(int i=0;i<n-1;i++)
        	{
        	    cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int j=0;j<n-1-i;j++)
        		{
        			if(b_arr[j]>b_arr[j+1])
        			{
        				int temp=b_arr[j+1];
        				b_arr[j+1]=b_arr[j];
        				b_arr[j]=temp;
        			}
        		    for(int i=0;i<n;i++)
            		{
            		    cout<<"\t"<<b_arr[i];
            		}
            		cout<<"\n\n";
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<n;i++)
        	{
        		cout<<"\t"<<b_arr[i];
        	}
    	}
    	else if(choice==2)
    	{
    	   cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<n;i++)
            {
                cout<<"\t"<<b_arr[i];
            }

        	for(int i=0;i<n-1;i++)
        	{
        	    cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int j=0;j<n-1-i;j++)
        		{
        			if(b_arr[j]<b_arr[j+1])
        			{
        				int temp=b_arr[j+1];
        				b_arr[j+1]=b_arr[j];
        				b_arr[j]=temp;
        			}
        		    for(int i=0;i<n;i++)
            		{
            		    cout<<"\t"<<b_arr[i];
            		}
            		cout<<"\n\n";
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<n;i++)
        	{
        		cout<<"\t"<<b_arr[i];
        	}
    	}
    	else
    	{
    	    cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    	}
    }
    else if(ch=='n')
    {
        cout<<"\n\n\t* * * Original Array Elements:* * *\n";
        for(int i=0;i<size;i++)
        {
            cout<<"\t"<<arr2[i];
        }

    	int choice;
    	cout<<"\n\n1.Ascending Order\n";
    	cout<<"\n2.Descending Order\n";

    	cout<<"\nEnter your choice:\t";
    	cin>>choice;

    	if(choice==1)
    	{
    	    cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<size;i++)
            {
                cout<<"\t"<<arr2[i];
            }

        	for(int i=0;i<size-1;i++)
        	{
        	    cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int j=0;j<size-1-i;j++)
        		{
        			if(arr2[j]>arr2[j+1])
        			{
        				int temp=arr2[j+1];
        				arr2[j+1]=arr2[j];
        				arr2[j]=temp;
        			}
        		    for(int i=0;i<size;i++)
            		{
            		    cout<<"\t"<<arr2[i];
            		}
            		cout<<"\n\n";
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}
    	}
    	else if(choice==2)
    	{
    	   cout<<"\n\n\t* * * Original Array Elements:* * *\n";
            for(int i=0;i<size;i++)
            {
                cout<<"\t"<<arr2[i];
            }

        	for(int i=0;i<size-1;i++)
        	{
        	    cout<<"\n\n\t\t* * * PASS "<<i+1<<" * * *\t\t\n";
        		for(int j=0;j<size-1-i;j++)
        		{
        			if(arr2[j]<arr2[j+1])
        			{
        				int temp=arr2[j+1];
        				arr2[j+1]=arr2[j];
        				arr2[j]=temp;
        			}
        		    for(int i=0;i<size;i++)
            		{
            		    cout<<"\t"<<arr2[i];
            		}
            		cout<<"\n\n";
        		}
        		cout<<"\n\t- - - - - - - - - - - - - - - - - -\n\n";
        	}

        	cout<<"\n\n\t* * * Elements after Sorting * * *\n";
        	for(int i=0;i<size;i++)
        	{
        		cout<<"\t"<<arr2[i];
        	}
    	}
    	else
    	{
    	    cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    	}
    }
    else
    {
        cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    }

}


void binary_search(int arr1[],int arr2[],int size)
{
    char ch;
    cout<<"Do you want to perform sorting with new elements (y,n):\t";
    cin>>ch;

    if(ch=='y')
    {
        int n;
        cout<<"\n\nEnter the size of the Array:\t";
        cin>>n;

        int bs_arr[n];

        for(int i=0;i<n;i++)
        {
            cout<<"Enter element "<<i+1<<" :\t";
    		cin>>bs_arr[i];
        }


        cout<<"\nEnter the item to search:\t";
        int item;
        cin>>item;

        int loc=-1;
        int beg=0,end=n-1;
        int mid;

        while(beg<=end)
        {
            mid=(beg+end)/2;
            cout<<"\n\nMiddle element is "<<bs_arr[mid]<<" found at index "<<mid<<"\n";
            if(item==bs_arr[mid])
            {
                loc=mid;
                break;
            }
            else if(item<bs_arr[mid])
            {
                end=mid-1;
                cout<<"\n\nupdated end index is: "<<end;
            }
            else
            {
                beg=mid+1;
                cout<<"\n\nupdated beginning index is: "<<beg<<"\n";
            }
        }

        if(loc==-1)
        {
            cout<<"\n\t* * * Element "<<item<<" is not found in the array * * *\n\n";
        }
        else
        {
           cout<<"\n\t* * * Element "<<item<<" is found at index "<<loc<<" * * *\n\n";
        }
    }

    else if(ch=='n')
    {
        cout<<"\nEnter the item to search:\t";
        int item;
        cin>>item;

        int loc=-1;
        int beg=0,end=size-1;
        int mid;

        while(beg<=end)
        {
            mid=(beg+end)/2;
            cout<<"\n\nMiddle element is "<<arr2[mid]<<" found at index "<<mid<<"\n";
            if(item==arr2[mid])
            {
                loc=mid;
                break;
            }
            else if(item<arr2[mid])
            {
                end=mid-1;
                cout<<"\n\nupdated end index is: "<<end;
            }
            else
            {
                beg=mid+1;
                cout<<"\n\nupdated beginning index is: "<<beg<<"\n";
            }
        }

        if(loc==-1)
        {
            cout<<"\n\t* * * Element "<<item<<" is not found in the array * * *\n\n";
        }
        else
        {
           cout<<"\n\t* * * Element "<<item<<" is found at index "<<loc<<" * * *\n\n";
        }

        for(int i=0;i<size;i++)
        {
            arr2[i]=arr1[i];
        }
    }

    else
    {
        cout<<"\n\n* * * * INVALID SELECTION * * * *\n\n";
    }

}



int main()
{
    do{
    cout<<"\n\n\t* * * * WELCOME TO ALGORITHM SIMULATOR * * * *\n";
//    int choice;
    int arr1[10];
    int arr2[10];
    int size;
      cout<<"\n\t\t* * * Choices you have * * *\n";
        cout<<"\t- - - - - - - - - - - - - - - - - - - - - - -";
        cout<<"\n\t1.Selection Sort\n";
        cout<<"\t2.Insertion Sort\n";
        cout<<"\t3.Bubble Sort\n";
        cout<<"\t4.Binary Search\n";
        cout<<"\t5.Linked List Operation\n";
        cout<<"\t6.Stack Operation\n";
        cout<<"\t7.Queue Operation\n";
        cout<<"\t0.Exit\n";


        cout<<"* * * Enter your choice: * * * :  ";
        cin>>choice;
        if(choice > 0 && choice < 5){
    		cout<<"\nEnter size of the Array:\t";
    		cin>>size;
    		arr1[size];
    		arr2[size];
    		cout<<"\n";
    		cout<<"\n";
    		for(int i=0;i<size;i++)
    		{
        		cout<<"Enter element "<<i+1<<" :\t";
        		cin>>arr1[i];
        		arr2[i]=arr1[i];
    		}
		}
        switch(choice)
        {
            case 1:selection_sort(arr1,arr2,size);break;
            case 2:insertion_sort(arr1,arr2,size);break;
            case 3:bubble_sort(arr1,arr2,size);break;
            case 4:binary_search(arr1,arr2,size);break;
            case 5: linked_list_operation();break;
            case 6: stack_operation();break;
            case 7: queue_operation();break;
            case 0:exit(0);break;
            default:cout<<"\nx x x Invalid Selection x x x\n";
        }
    }while(choice!=0);
}
