// Lily Tang
#ifndef Hash_h
#define Hash_h

#include <string>

template <class T, class K>
struct HashNode {
	T data;
	K key;
	int hashkey;
	// HashNode<T, K> *nextPtr;
	HashNode() {
		data = NULL;
		key = -1;
		hashkey = NULL;
	}
	HashNode(T item, K keyitem, int i) {
		this->data = item;
		this->key = keyitem;
		this->hashkey = i;
	}
	void operator= (const HashNode<T, K> &rightHandItem) const {
		key = rightHandItem.key;
		data = rightHandItem.data;
		hashkey = rightHandItem.hashkey;
	}
};

template <class T, class K>
class HashMap {
private:
	HashNode<T, K> **arr;   // pointer to array
	int buckets;         // num of buckets
	int collision;      // # of collisions
	double items;          // # of items in hashmap
protected:
	int getsum(int n) {
		int sum = 0;
		while (n != 0)
		{
			sum = sum + n % 10;
			n = n / 10;
		}
		return sum;
	}
public:
	HashMap(int v);
	virtual ~HashMap() {
		delete arr;
	}
	int hashFunction(K date);
	double getLoadFactor();
	void insert(T item, K keyitem);
	void deleteItem(K keyitem);
	T search(K keyitem);
	int find(K keyitem);
	bool isEmpty();
	double getItems();
	int getCollisions() {
		return collision;
	};
	void display();
};

template <class T, class K>
HashMap<T, K>::HashMap(int v) {
	buckets = v;
	items = 0.0;
	collision = 0;
	arr = new HashNode<T, K>*[buckets];
	// initializa all array elements = NULL
	for (int i = 0; i < buckets; i++) {
		// HashNode<T, K> *thing = new HashNode<T, K>(NULL, NULL);
		arr[i] = NULL;
	}
}
/*************************************************************************
This function assigns an index to a key

Key % # of buckets

Pre: key
Post: return index
*************************************************************************/
template <class T, class K>
int HashMap<T, K>::hashFunction(K date) {
	while (date > 9) {
		date = getsum(date);
	}
	return date;
}

template <class T, class K>
double HashMap<T, K>::getLoadFactor() {
	return (items / buckets) * 100;
}

/*************************************************************************
This function inserts item into map using a hush function and
quadratic probing

Param: item = item type's data; keyitem is the key item
Post: item added to hash table
*************************************************************************/
template <class T, class K>
void HashMap<T, K>::insert(T item, K keyitem) {
	if (items >= buckets)
		return;
	// use hash function to find the bucket index
	int index = hashFunction(keyitem);
	int hashID = index % buckets;
	// find next free space
	for (int j = 0; j < buckets; j++) {
		// use quadratic probing to find the next empty bucket
		// rehash
		hashID = (hashID + j*j) % buckets;
		// if space is empty,
		if (arr[hashID] == nullptr) {
			if (j > 0)
				collision++;
			items++;
			arr[hashID] = new HashNode<T, K>(item, keyitem, hashID);
			std::cout << item << "------> is added to hash index " << hashID << std::endl;
			break;
		}
	}
}
/*************************************************************************
This function deletes a key from the hash table

Hash index found by calling hashFunction with key
Set comparisons to 0
Indexed linked list searched from start to end for key
If a node matching the key is found, it is deleted from the hash table
Decriment items by 1
Else nothing happens (recommend using searchItemExists first to avoid this)

Pre: key = item being searched for deletion
Post: node matching key is deleted
*************************************************************************/
template <class T, class K>
void HashMap<T, K>::deleteItem(K keyitem) {
	int hashid = find(keyitem);
	if (hashid > -1) {
		arr[hashid] = NULL;
		items--;
		std::cout << "Item deleted!!\n\n";
	}
	else {
		throw "Invalid data/key entered!";
	}
}
/*************************************************************************
This function searches for a key index of an item and returns the int

Pre: keyitem = item being searched for
Post: return int pos for matching key
*************************************************************************/
template <class T, class K>
int HashMap<T, K>::find(K keyitem) {
	// get the hash index of key
	//int index = hashFunction(keyitem);
	//int hashID = index % buckets;
	int pos = -1;
	for (int j = 0; j < buckets; j++) {
		//hashID = (index + j*j) % buckets;
		// not null and key match
		if (arr[j] != nullptr && arr[j]->key == keyitem) {
			pos = j;
			break;
		}
	}
	return pos;
}

/*************************************************************************
This function searches for a key index of an item and returns the data
it uses the find function.

Pre: keyitem = item being searched for
Post: return data object of the matching key
*************************************************************************/
template <class T, class K>
T HashMap<T, K>::search(K keyitem) {
	int hashid = find(keyitem);
	if (hashid > -1)
		return arr[hashid]->data;
	else {
		// std::cout << "Invalid data!" << std::endl;
		throw "Invalid data!";
	}
}

template <class T, class K>
bool HashMap<T, K>::isEmpty() {
	return items == 0;
}

template <class T, class K>
double HashMap<T, K>::getItems() {
	return items;
}

template <class T, class K>
void HashMap<T, K>::display() {
	for (int i = 0; i < buckets; i++) {
		if (arr[i] != NULL)
			std::cout << "index [" << arr[i]->hashkey << "] --> " << arr[i]->data << std::endl;
	}
}

#endif /* Hash_h */