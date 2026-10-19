# Recursion and Tower of Hanoi
So to solve tower of hanoi problem we need to do few steps: 
1. Checking the base case which is when we only have 1 disk
2. Otherwise we need to first put all n-1 disks into aux from source
3. Then we have the last one which is n, so
that one can go to dest now, so we do n from source to dest printing. 
4. Now we just put all those n-1 disks on top of dest from aux

So the code is like: 

    public void towerOfHanoi(int n, String source, String aux, String dest){
        
        // If only 1 disk, make the move and return.
        if (n == 1){
            System.out.println(n + " from " + source + " --> " + dest); 
            return; 
        }

        // Move top n-1 disks from source to aux,
        // using dest as auxiliary.
        towerOfhanoi(n-1, source, dest, aux); 

        // Move remaining disk from source to dest.
        System.out.println(n + " from " + source + " --> " + dest); 

        // Move n-1 disks from aux to dest,
        // using source as auxiliary.
        towerOfHanoi(n-1, aux, source, dest); 
    }