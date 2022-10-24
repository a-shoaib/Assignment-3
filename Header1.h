void insertAfter(vector<int> V, int firstValue, int secondValue);

class l_list {

private:
	struct node {
		int num;
		int occurences = 1;
		node* next;
	};
	node* head, * cursor, * prev;

public:
	l_list();
	void toFirst();
	void insert_first(int data);
	void insert_before(int position, int data);

	void insert_after(int position, int data);
	void insert_end(int data);
	void remove_node(int position);
	void print();

	l_list vec_list(vector<int> V);

	int list_sum();
};
