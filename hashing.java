import java.util.*;
class Hashing{

    
    boolean isPrime(int n){
        for(int i=2;i<n;i++){
            if(n%i==0){
                // System.out.println("Prime");
                return false;
            }
        }
        return true;
    }
    int next_prime(int n){
        while(!isPrime(n)){
            // System.out.println("Next Prime");
            n++;
        }
        return n;
    }
    //To insert elements into the hash table
    void insert(int arr[],int n){
        int location;
        location = n%arr.length;
        while(arr[location]!=0){
            location=(location+1)%arr.length;
        }
        arr[location]=n;
    }
    //To retrieve elements from the hash table
    int search(int arr[],int n){
        int location;
        location = n%arr.length;
        if(arr[location]==n){
            return location;
        }
        while(arr[location]!=n){
            location=(location+1)%arr.length;
        }
        return location;
    }

    void display(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

    public static void main(String args[]){
        Scanner sc= new Scanner(System.in);
        Hashing obj=new Hashing();
        System.out.println("Enter number of elements");
        int n=sc.nextInt();
        int hash_size=obj.next_prime(n);
        int hash_table[]=new int[hash_size];
        System.out.println("Enter "+n+" elements");
        for(int i=0;i<n;i++){
            obj.insert(hash_table,sc.nextInt());
        }
        int ch;
        do{
            System.out.println("Enter 1 to search an element");
            System.out.println("Enter 2 to display hash table");
            System.out.println("Enter -1 to exit");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                System.out.println("Enter the element to be searched");
                int x=obj.search(hash_table,sc.nextInt());
                System.out.println(hash_table[x]+" was found in location "+x);
                break;
                case 2:
                System.out.println("Hash Table Size:"+hash_size);
                System.out.println("Hash Table-Linear Probing");
                obj.display(hash_table);
                break;
                case -1:
                System.out.println("Exit");
                break;
            }
        }while(ch!=-1);
        sc.close();
    }

}