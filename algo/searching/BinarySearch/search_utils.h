#include <iostream>

class SearchUtil
{
    private :
    SearchUtil(){};
    ~SearchUtil(){
		delete instance;
	};
    bool created = false;
    static SearchUtil * instance;
  public:
    static SearchUtil * Get() {
        if(!instance) {
            instance = new SearchUtil();
        }
        return instance;
    }
	static void Cleanup() {
		delete instance;
	}
    int BinarySearchRecursive(int * arr, int size, int item);
	int BinarySearchIterative(int * arr, int size, int item);
	int BinarySearchIterativeFloorValue(int * arr, int size, int item);

    private:
    int BSUtil(int * arr, int l, int r, int item);
};
