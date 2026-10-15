#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char const *argv[]){
	char c = 'c' ;
	int f[2] , s[2] ;
	pipe(f);
	pipe(s);
	if (fork() == 0 ){
		close(s[0]);
		close(f[1]);
		read(f[0] ,&c,sizeof(c));
		fprintf(1,"%d : receive ping \n",getpid());
		write(s[1],&c,sizeof(c));
		close(f[0]);
		close(s[1]);
		exit(0);
	}else{
		close(f[0]);
		close(s[1]);
		write(f[1],&c,sizeof(c));
		read(s[0] ,&c,sizeof(c));
		fprintf(1,"%d : receive pong \n",getpid());
		close(s[0]);
		close(f[1]);
		exit(0);

	}
	
}
