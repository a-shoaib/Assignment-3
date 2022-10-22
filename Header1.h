void insertAfter(vector<int> V, int firstValue, int secondValue) {
	vector<int>::iterator Iter = V.begin();
	while (Iter != V.end()) {
		if (*Iter = firstValue) {
			V.insert(Iter + 1, secondValue);
		}
	}
}
class l_list {

private:
	struct node {
		int num;
		int occurences = 1;
		node* next;
	};
	node* head, * cursor, * prev;

public:
	l_list() {
		head = NULL;
		cursor = NULL;
		prev = NULL;
	}
	void toFirst() {
		cursor = head;
		prev = NULL;
	}
	void insert_first(int data) {
		head = new node;
		head->num = data;
		head->next = NULL;
		cursor = head;
		cursor->occurences = 1;
	}
	void insert_before(int position, int data) {		//position represents the node we want to insert before 
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
	void insert_after(int position, int data) {		//position presents the node we want to insert after 
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
	void insert_end(int data) {
		toFirst();
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}	//by end of while-loop, cursor will be pointing to last element

		node* p = new node;
		p->num = data;
		p->next = NULL; //because we want the node to which p points to be the last
		cursor->next = p;
	}
	void remove_node(int position) {		// position is node we want to delete
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
	void print() {
		toFirst();
		while (cursor->next != NULL) {
			cout << "num:" << cursor->num << "	occurences: " << cursor->occurences << endl;
			cursor = cursor->next;
		}
	}
	l_list vec_list(vector<int> V) {
		l_list list;
		vector<int>::iterator Iter = V.begin();
		list.insert_first(*Iter);

		for (Iter = V.begin(); Iter <= V.end(); Iter++) {
			cursor = list.head;
			do {
				
				if (cursor->num == *Iter) {
					cursor->occurences++;
					Iter++;
					continue;
				}
				if (cursor->next == NULL) {
					list.insert_end(*Iter);
					Iter++;
					continue;
				}
				cursor = cursor->next;
			} while (Iter <= V.size());
		}

		return list;
	}

	int list_sum() {
		toFirst();
		int sum = 0;
		while (cursor != NULL) {
			sum += cursor->num;
			cursor = cursor->next;
		}
		return sum;
	}

};
