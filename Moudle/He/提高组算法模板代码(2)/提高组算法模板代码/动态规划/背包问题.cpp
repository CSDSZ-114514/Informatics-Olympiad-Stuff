//背包问题：n件商品的商店，背包容量为V的背包，已知每件商品的体积c[i], 价值w[i]
//求最大简直 

//01背包：每件物品只有一件
	for(int i=1;i<=n;i++){
		for(int j=1;j<=V;j++){
			f[i][j] = f[i-1][j]; 
			if(j>=c[i]){
				f[i][j]=max(f[i][j],f[i-1][j-c[i]]+w[i]);
			}		
		}
	}
	//01背包降维 
	for(int i=1;i<=n;i++){
		for(int j=V;j>=1;j--){
			if(j>=c[i]){
				f[j]=max(f[j],f[j-c[i]]+w[i]);
			}		
		}
	} 
	
//完全背包：每件物品有无数件
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=V; j++) {
			f[i][j] = f[i-1][j];
			if(j>=c[i]) {
				f[i][j] = max(f[i][j], f[i][j-c[i]]+w[i]);
			}
		}
	} 
	//完全背包降维 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=V; j++) {
			if(j>=c[i]) {
				f[j] = max(f[j], f[j-c[i]]+w[i]);
			}
		}
	} 
	
//多重背包：每件物品有固定件数m[i]件 
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=V; j++) {
			for(int k=0; k<=m[i]; k++) {
				if(j-k*v[i] >= 0) {
					f[i][j] = max(f[i][j], f[i-1][j-k*c[i]]+k*w[i]);
				}								
			}			
		} 
	} 
	
	
	
