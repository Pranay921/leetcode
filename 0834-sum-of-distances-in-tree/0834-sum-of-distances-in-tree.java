class Solution {
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
     
        
        Map<Integer,List<Integer>> graph = new HashMap<>();
        for(int i=0;i<n;i++){
            graph.put(i,new ArrayList<>());
        }
        for(int[] ed:edges){
            int u=ed[0],v=ed[1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        
        int[] res = new int[n],count=new int[n];
         dfs(-1,0,graph,res,count);
        dfs2(-1,0,graph,res,count,n);                        
        return res;
    }
    
        
    private void dfs(int p,int u,Map<Integer,List<Integer>> graph,int[] res,int[] count){
        
        for(int v:graph.get(u)){
            if(v==p)continue;
            
            dfs(u,v,graph,res,count);             
            count[u]+=count[v];
            res[u]+=res[v]+count[v];
        }
        count[u]++;
    
    }
    
    private void dfs2(int p,int u,Map<Integer,List<Integer>> graph,int[] res,int[] count,int n){
                
        for(int v:graph.get(u)){
            if(v==p) continue;
            res[v]= (res[u]-count[v]) + ( n-count[v]);
            dfs2(u,v,graph,res,count,n);            
        }
    }
}