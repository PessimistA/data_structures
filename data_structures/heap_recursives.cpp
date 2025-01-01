void recursive_percolateDown(int hole,int tmp) {
    if (!(hole<=the_size/2))
    {
        array[hole] = tmp;
        return;
    }
    int child;
    child = hole * 2;
    if (child != the_size && array[child + 1] < array[child]) {
        child++;  
    }
    if (array[child] < tmp) {
        array[hole] = array[child]; 
    }
    recursive_percolateDown(child,tmp);
}

void insert_recursive(int x, int hole) {
    if (!(x<array[hole/2]))
    {
        array[hole] = x;
        return;
    }
    array[hole] = array[hole / 2];
    insert_recursive(x, hole / 2);

}
