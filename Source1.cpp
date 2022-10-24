#include"Header1.h"

void insertAfter(vector<int> V, int firstValue, int secondValue) {
	vector<int>::iterator Iter = V.begin();
	while (Iter != V.end()) {
		if (*Iter = firstValue) {
			V.insert(Iter + 1, secondValue);
		}
	}
}


	l_list::l_list() {
		head = NULL;
		cursor = NULL;
		prev = NULL;
	}
	l_list::toFirst() {
		cursor = head;
		prev = NULL;
	}
	l_list::insert_first(int data) {
		head = new node;
		head->num = data;
		head->next = NULL;
		cursor = head;
		cursor->occurences = 1;
	}
	l_list::insert_before(int position, int data) {		//position represents the node we want to insert before 
		toFirst();
		int count = 1;
		while (cursor->next != NULL && count != position) {
			cursor = cursor->next;
			count++;
		}

		if (cursor->next == NULL) {
			cout << "Error";
			return;
		}
		node* p = new node;
		p->num = data;
		p->next = cursor->next;
		cursor->next = p;
	}
	l_list::insert_after(int position, int data) {		//position presents the node we want to insert after 
		toFirst();
		int count = 1;
		while (cursor->next != NULL && count != position) {
			cursor = cursor->next;
		}
		if (cursor->next == NULL) {
			cout << "Error";
			return;
		}
		cursor = cursor->next;	//cursor points to position

		node* p = new node;
		p->num = data;
		p->next = cursor->next;
		cursor->next = p;
	}
	l_list::insert_end(int data) {
		toFirst();
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}	//by end of while-loop, cursor will be pointing to last element

		node* p = new node;
		p->num = data;
		p->next = NULL; //because we want the node to which p points to be the last
		cursor->next = p;
	}
	l_list::remove_node(int position) {		// position is node we want to delete
		toFirst();
		int count = 1;
		while (cursor->next != NULL && count != position) {
			cursor = cursor->next;
			count++;
		}
		if (cursor->next == NULL) {
			cout << "Error";
			return;
		}
		prev = cursor;			//prev points to node before position
		cursor = cursor->next;	//cursor points to position	
		prev->next = cursor->next; //prev->next points to node after position
		delete cursor;
	}
	l_list::print() {
		toFirst();
		while (cursor->next != NULL) {
			cout << "num:" << cursor->num << "	occurences: " << cursor->occurences << endl;
			cursor = cursor->next;
		}
	}
	//traverse -> if v[i] == cursor increment occurence -> if end no occurence append
	l_list::vec_list(vector<int> V) {

		int i = 0;
		bool test = false;
		insert_first(V[i]);
		i++;
		do {
			toFirst();
			while (cursor->next != NULL) {
				if (V[i] == cursor->num) {
					cursor->occurences++;
					bool test = true;
				}
				cursor = cursor->next;
			}
			if (!test) {
				node * 0 = new node;
				p->num = V[i];
				p->next = NULL;
				cursor->next = NULL: //to insert at the end
			}
			test = false;
			i++;
		} while (i <= V.size());


	}

	l_list::list_sum() {
		toFirst();
		int sum = 0;
		while (cursor != NULL) {
			sum += cursor->num;
			cursor = cursor->next;
		}
		return sum;
	}

};
