#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


	typedef struct ct
		{
		char titlu[20],autor[20],lb[10],nume[15];
		int an,nr_ex,cota,ok,ann,luna,zi;
		struct ct *urm;
		}teh;
			
	typedef struct cl
		{
			char titlul[20],autorl[20],tip[10],numel[20];
			int an_apar,okl,annl,lunal,zil;
			struct cl *urml;
		}lit;
		
	typedef struct cc
		{
			char titluc[20],tema[20],org[25],loc[15],numec[15];
			int per,nr_art,okc,annc,lunac,zic;
			struct cc *urmc;
		}conf;
	


	teh* adaugare_teh(teh *ult)
{
	teh *q;

	q=(teh*)malloc(sizeof(teh));

	fflush(stdin);
	printf("\ntitlul cartii tehnice:");
	gets(q->titlu);
	printf("\nautor:");
	gets(q->autor);
	printf("\nlimba:");
	gets(q->lb);
	printf("\nan aparitie:");
	scanf("%d",&(q->an));
	printf("\nnr exemplare:");
	scanf("%d",&(q->nr_ex));
	printf("\ncota carte:");
	scanf("%d",&(q->cota));
	printf("\ncartea este imprumutata?\n\nintroduceti 1daca da si 0 daca nu:");
	scanf("%d",&(q->ok));
	
	if(q->ok==1) 
	{
		
	fflush(stdin);
	printf("\nnumele celui care a imprumutat cartea:");
	gets(q->nume);
	printf("\ndata returnarii cartii:\n an/luna/zi:\n");
	scanf("%d %d %d",&(q->ann),&(q->luna),&(q->zi));

	}

	ult->urm=q;
	ult=q;
	ult->urm=NULL;
	return ult;
}

	lit* adaugare_lit(lit *ult)
{
	lit *ql;

	ql=(lit*)malloc(sizeof(lit));

	fflush(stdin);
	printf("\ntitlul cartii de literatura:");
	gets(ql->titlul);
	printf("\nautor:");
	gets(ql->autorl);
	printf("\nlimba:");
	gets(ql->tip);
	printf("\nan aparitie:");
	scanf("%d",&(ql->an_apar));
	printf("\ncartea este imprumutata? \n\nintroduceti 1 daca da si 0 daca nu\n");
	scanf("%d",&(ql->okl));
	
	if(ql->okl==1) 
	{
		fflush(stdin);
	printf("\nnumele celui care a imprumutat cartea:");
	gets(ql->numel);
	printf("\ndata returnarii cartii:\n an/luna/zi:\n");
	scanf("%d %d %d",&(ql->annl),&(ql->lunal),&(ql->zil));

	}

	ult->urml=ql;
	ult=ql;
	ult->urml=NULL;
	return ult;
}

	conf* adaugare_vol_conf(conf *ul)
	{
		
		conf *q;

		q=(conf*)malloc(sizeof(conf));

		printf("\ntitlul volumului de conferinta:");
		fflush(stdin);
		gets(q->titluc);
		printf("\ntematica volumului:");
		gets(q->tema);
		printf("\nechipa de organizatori:");
		gets(q->org);
		printf("\nlocatia conferintei:");
		gets(q->loc);
		printf("\nperioada in care a avut loc conferinta:");
		scanf("%d",&(q->per));
		printf("\nnr articole publicate:");
		scanf("%d",&(q->nr_art));
		printf("\nvolumul este imprumutat?\n\nintroduceti 1 daca da si 0 daca nu:");
		scanf("%d",&(q->okc));
		
		if(q->okc==1)
		{
			
		fflush(stdin);
		printf("\nnumele celui care a imprumutat volumul:");
		gets(q->numec);
		printf("\ndata returnarii volumului:\n an/luna/zi:");
		scanf("%d %d %d",&(q->annc),&(q->lunac),&(q->zic));
		
		}

		ul->urmc=q;
		ul=q;
		ul->urmc=NULL;
		return ul;
	}


	void afisare_teh(teh *prim)
{
	teh *q;
	printf("\nCarti tehnice:\n");
	for(q=prim;q!=NULL;q=q->urm)
		printf("-%s\n",q->titlu);
}

	void afisare_lit(lit *prim)
{
	lit *q;
	printf("\nCarti de literatura:\n");
	for(q=prim;q;q=q->urml)
		printf("-%s\n",q->titlul);
}

	void afisare_conf(conf *prim)
{
	conf *q;
	printf("\nVolume cu articolele acceptate la diverse conferinþe:\n");
	for(q=prim;q;q=q->urmc)
		printf("-%s\n",q->titluc);
}

	void afisare_ordonat_tot(char x[50][20],int nr)
{
	char aux[50];
	int i,j;

	printf("\nToate cartile in ordine alfabetica:\n");
	
	for(i=1;i<nr;i++)
		for(j=i;j<=nr;j++)
			if(stricmp(x[i],x[j])>0) 
			{	
				strcpy(aux,x[i]);
				strcpy(x[i],x[j]);
				strcpy(x[j],aux);
			}

	for(i=1;i<=nr;i++)
		printf("* %s\n",x[i]);
}

	void cautare_teh(teh *prim,char atr[20])
{
	teh *q;
	int ok=0;

	for(q=prim;q;q=q->urm)
		if(stricmp(q->autor,atr)==0) { ok=1;   printf("			*%s %s\n",q->titlu,q->autor); }

	if(ok==0) printf("\nNu exista carti tehnice cu acest nume de autor.\n");
}
	
	void cautare_lit(lit *prim,char atr[20])
{
	lit *q;
	int ok=0;

	for(q=prim;q;q=q->urml)
		if(stricmp(q->autorl,atr)==0) { ok=1;   printf("			*%s %s\n",q->titlul,q->autorl); }

	if(ok==0) printf("\nNu exista carti de literatura cu acest nume de autor.\n");
}

	void cautare_tematica(conf *prim,char t[20])
{
	conf *q;
	int ok=0;

	for(q=prim;q;q=q->urmc)
		if(stricmp(q->tema,t)==0) { ok=1;   printf("		-%s  cu tematica:  %s\n",q->titluc,q->tema); }

	if(ok==0) printf("\nNu exista volume cu astfel de tematica.\n");
}

	teh* imprumut_teh(teh *prim,char t[20])
{
	teh *q;
	int okk=0;

	for(q=prim;q;q=q->urm)
	{
		if(stricmp(q->titlu,t)==0)
			if(q->ok==0) 
			{
				q->ok=1;   
				printf("\nnumele celui care imprumuta:");
				fflush(stdin);
				gets(q->nume);
				printf("\ndata returnarii cartii:\n an/luna/zi:\n");
				scanf("%d %d %d",&(q->ann),&(q->luna),&(q->zi));
				okk=1;
				return prim;
				
			}

	}

	if(okk==0) return NULL;
}

	lit* imprumut_lit(lit *prim,char t[20])
{
	lit *q;
	int ok=0;

	for(q=prim;q;q=q->urml)
	{
		if(stricmp(q->titlul,t)==0)
			if(q->okl==0) 
			{
				q->okl=1;   
				printf("\nnumele celui care imprumuta:");
				fflush(stdin);
				gets(q->numel);
				printf("\ndata returnarii cartii:\n an/luna/zi:\n");
				scanf("%d %d %d",&(q->annl),&(q->lunal),&(q->zil));
				ok=1;
				return prim;
				
			}
		
	
	}

	if(ok==0) return NULL;

}

	conf* imprumut_conf(conf *prim,char t[20])
{
	conf *q;
	int ok=0;

	for(q=prim;q;q=q->urmc)
	{
		if(stricmp(q->titluc,t)==0)
			if(q->okc==0) 
			{
				q->okc=1;   
				printf("\nnumele celui care imprumuta:");
				fflush(stdin);
				gets(q->numec);
				printf("\ndata returnarii cartii:\n an/luna/zi:\n");
				scanf("%d %d %d",&(q->annc),&(q->lunac),&(q->zic));
				ok=1;
				return prim;
				
			}


	}

	if(ok==0) return NULL;
}


	teh* restituire_teh(teh *prim,char t[20])
{
	teh *q;
	int okk=0;

	for(q=prim;q;q=q->urm)
	{
			if(stricmp(q->titlu,t)==0)
			
				if(q->ok==1)
			{
			q->ok=0;
			okk=1;
			return prim;
			}
	}
	
	if(okk==0) return NULL;
}

	lit* restituire_lit(lit *prim,char t[20])
{
	lit *q;
	int ok=0;

	for(q=prim;q;q=q->urml)
		
		{
			if(stricmp(q->titlul,t)==0)
				if(q->okl==1)
			{
			q->okl=0;
			ok=1;
			return prim;
			}
	}
	if(ok==0) return NULL;
}

	conf* restituire_conf(conf *prim,char t[20])
{
	conf *q;
	int ok=0;

	for(q=prim;q;q=q->urmc)
		{
			if(stricmp(q->titluc,t)==0)
			if(q->okc==1)
			{
			q->okc=0;
			ok=1;
			return prim;
			}
	}
	if(ok==0) return NULL;
}

	void afisare_imprumut_teh(teh *prim,int x,int y,int w)
{
	teh *q;
	for(q=prim;q;q=q->urm)
		{
			if(q->ok==1) 
			if(q->ann>x) printf("	-%s   %d   <%d %d %d>\n",q->titlu,q->ok,q->ann,q->luna,q->zi);
			else 
			{
				if(q->ann==x)
					
					{
						if(q->luna>y) printf("	-%s   %d   <%d %d %d>\n",q->titlu,q->ok,q->ann,q->luna,q->zi);
						if(q->luna==y&&q->zi>w) printf("	-%s   %d   <%d %d %d>\n",q->titlu,q->ok,q->ann,q->luna,q->zi);

				    }
			}
	   }
}

	void afisare_imprumut_lit(lit *prim,int x,int y,int w)
{
	lit *q;

	for(q=prim;q;q=q->urml)
		if(q->okl==1) 
			{

				if(q->annl>x) printf("	-%s   %d   <%d %d %d>\n",q->titlul,q->okl,q->annl,q->lunal,q->zil);
				else if(q->annl==x)
					
					{
						if(q->lunal>y) printf("	-%s   %d   <%d %d %d>\n",q->titlul,q->okl,q->annl,q->lunal,q->zil);
						else 	if(q->lunal==y&&q->zil>w) printf("	-%s   %d   <%d %d %d>\n",q->titlul,q->okl,q->annl,q->lunal,q->zil);
				    }
				
			}
		
}

	void afisare_imprumut_conf(conf *prim,int x,int y,int w)
{
	conf *q;

	for(q=prim;q;q=q->urmc)
		{
			if(q->okc==1) 
			if(q->annc>x) printf("	-%s   %d   <%d %d %d>\n",q->titluc,q->okc,q->annc,q->lunac,q->zic);
			else 
			{
				if(q->annc==x)
					
					{
						if(q->lunac>y) printf("	-%s   %d   <%d %d %d>\n",q->titluc,q->okc,q->annc,q->lunac,q->zic);
						if(q->lunac==y&&q->zic>w) printf("	-%s   %d   <%d %d %d>\n",q->titluc,q->okc,q->annc,q->lunac,q->zic);

				    }
			}
	}
}

	teh* stergere_teh(teh *prim,teh *ult,char t[20])
{
	teh *b,*q;

	if(stricmp(prim->titlu,t)==0) 
	{
		b=prim;
		prim=prim->urm;
		free(b);
	}
	else
	{
		q=prim;
		while(q->urm!=NULL&&stricmp(q->urm->titlu,t))
			q=q->urm;

		if(q->urm==ult&&stricmp(q->urm->titlu,t)==0)
			{
				ult=q;
				ult->urm=NULL;
				free(q->urm);
		}

		else 
		{
			b=q->urm;
			q->urm=q->urm->urm;
			free(b);
		}

	}
		 return prim;
	}

	lit* stergere_lit(lit *prim,lit *ult,char t[20])
{
	lit *b,*q;

	if(stricmp(prim->titlul,t)==0) 
	{
		b=prim;
		prim=prim->urml;
		free(b);
	}
	else
	{
		q=prim;
		while(q->urml!=NULL&&stricmp(q->urml->titlul,t))
			q=q->urml;

		if(q->urml==ult&&stricmp(q->urml->titlul,t)==0)
			{
				ult=q;
				ult->urml=NULL;
				free(q->urml);
		}

		else 
		{
			b=q->urml;
			q->urml=q->urml->urml;
			free(b);
		}

	}
		return prim;
	}

	conf* stergere_conf(conf *prim,conf *ult,char t[20])
{
	conf *b,*q;

	if(stricmp(prim->titluc,t)==0) 
	{
		
		b=prim;
		prim=prim->urmc;
		free(b);
	}
	else
	{
		q=prim;
		while(q->urmc!=NULL&&stricmp(q->urmc->titluc,t))
			q=q->urmc;

		if(q->urmc==ult&&stricmp(q->urmc->titluc,t)==0)
		{

				b=q->urmc;
				ult=q;
				ult->urmc=NULL;
				free(b);
		}

		else 
		{
			b=q->urmc;
			q->urmc=q->urmc->urmc;
			free(b);
		}

	}

		return prim;
}
		
	int caut_teh(teh *prim,teh *ult,char t[20])
	{
		int ok=0;
		teh *q;
		for(q=prim;q;q=q->urm)
			if(stricmp(q->titlu,t)==0) ok++;
		return ok;
	}


	int caut_lit(lit *prim,lit  *ult,char t[20])
	{
		int ok=0;
		lit *q;
		for(q=prim;q;q=q->urml)
			if(stricmp(q->titlul,t)==0) ok++;
		return ok;
	}

	int caut_conf(conf *prim,conf *ult,char t[20])
	{
		int ok=0;
		conf *q;
		for(q=prim;q;q=q->urmc)
			if(stricmp(q->titluc,t)==0) ok++;
		return ok;
	}


int main()
{
	FILE *f,*g,*h,*fo;
	teh *p,*q,*u,*s;
	lit *pl,*ql,*ul,*j;
	conf *pc,*qc,*uc,*t;

	char linie[255],liniel[255],liniec[255],*rez,*rez1,*rez2,v[50][20],caut_autor[20],tematica[20],tit[20],titl[20],tt[20];
	int opt,i,a,l,z;

	fo=fopen("rezultate.txt","wt");


	if((f=fopen("tehnice.txt","rt"))!=NULL)
	{
		p=(teh*)malloc(sizeof(teh));
		u=(teh*)malloc(sizeof(teh));
		
			rez=fgets(linie,255,f);
			
				strcpy(p->titlu,strtok(linie," "));
				strcpy(p->autor,strtok(NULL," "));
				strcpy(p->lb,strtok(NULL," "));
				p->an=atoi(strtok(NULL," "));
				p->nr_ex=atoi(strtok(NULL," "));
				p->cota=atoi(strtok(NULL," "));
				p->ok=atoi(strtok(NULL," "));
				if(p->ok==1)
				{
					fflush(stdin);
					strcpy(p->nume,strtok(NULL," "));
					p->ann=atoi(strtok(NULL," "));
					p->luna=atoi(strtok(NULL," "));
					p->zi=atoi(strtok(NULL," "));

				}

				u=p;
				u->urm=NULL;


			rez=fgets(linie,255,f);
			
			while(rez!=NULL)
			{
	
				q=(teh*)malloc(sizeof(teh));
				strcpy(q->titlu,strtok(linie," "));
				strcpy(q->autor,strtok(NULL," "));
				strcpy(q->lb,strtok(NULL," "));
				q->an=atoi(strtok(NULL," "));
				q->nr_ex=atoi(strtok(NULL," "));
				q->cota=atoi(strtok(NULL," "));
				q->ok=atoi(strtok(NULL," "));
				if(q->ok==1)
				{
					fflush(stdin);
					strcpy(q->nume,strtok(NULL," "));
					q->ann=atoi(strtok(NULL," "));
					q->luna=atoi(strtok(NULL," "));
					q->zi=atoi(strtok(NULL," "));
				}
				u->urm=q;
				u=q;
				u->urm=NULL;				
				
			rez=fgets(linie,255,f);
			}

		fclose(f);
	}
	
	if((g=fopen("literatura.txt","rt"))!=NULL)
	{
		pl=(lit*)malloc(sizeof(lit));
		ul=(lit*)malloc(sizeof(lit));
		
		rez1=fgets(liniel,255,g);
		strcpy(pl->titlul,strtok(liniel," "));
		strcpy(pl->autorl,strtok(NULL," "));
		strcpy(pl->tip,strtok(NULL," "));
		pl->an_apar=atoi(strtok(NULL," "));
		pl->okl=atoi(strtok(NULL," "));
		if(pl->okl==1)
		{
			fflush(stdin);
			strcpy(pl->numel,strtok(NULL," "));
			pl->annl=atoi(strtok(NULL," "));
			pl->lunal=atoi(strtok(NULL," "));
			pl->zil=atoi(strtok(NULL," "));
		}

		ul=pl;
		ul->urml=NULL;
		
		rez1=fgets(liniel,255,g);
		while(rez1!=NULL)
		{
			ql=(lit*)malloc(sizeof(lit));
			strcpy(ql->titlul,strtok(liniel," "));
			strcpy(ql->autorl,strtok(NULL," "));
			strcpy(ql->tip,strtok(NULL," "));
			ql->an_apar=atoi(strtok(NULL," "));
			ql->okl=atoi(strtok(NULL," "));
			if(ql->okl==1)
			{
				fflush(stdin);
				strcpy(ql->numel,strtok(NULL," "));
				ql->annl=atoi(strtok(NULL," "));
				ql->lunal=atoi(strtok(NULL," "));
				ql->zil=atoi(strtok(NULL," "));
			}

			ul->urml=ql;
			ul=ql;
			ul->urml=NULL;

			rez1=fgets(liniel,255,g);
		}
		fclose(g);
	}


	if((h=fopen("vol_conferinta.txt","rt"))!=NULL)
	{
		pc=(conf*)malloc(sizeof(conf));
		uc=(conf*)malloc(sizeof(conf));
		
		rez2=fgets(liniec,255,h);
			
						
				strcpy(pc->titluc,strtok(liniec," "));
				strcpy(pc->tema,strtok(NULL," "));
				strcpy(pc->org,strtok(NULL," "));
				strcpy(pc->loc,strtok(NULL," "));
				pc->per=atoi(strtok(NULL," "));
				pc->nr_art=atoi(strtok(NULL," "));
				pc->okc=atoi(strtok(NULL," "));

				if(pc->okc==1)
				{
					fflush(stdin);
					strcpy(pc->numec,strtok(NULL," "));
					pc->annc=atoi(strtok(NULL," "));
					pc->lunac=atoi(strtok(NULL," "));
					pc->zic=atoi(strtok(NULL," "));

				}

				uc=pc;
				uc->urmc=NULL;


			rez2=fgets(liniec,255,h);
			
			while(rez2!=NULL)
			{
	
				
				
				qc=(conf*)malloc(sizeof(conf));
				
				strcpy(qc->titluc,strtok(liniec," "));
				strcpy(qc->tema,strtok(NULL," "));
				strcpy(qc->org,strtok(NULL," "));
				strcpy(qc->loc,strtok(NULL," "));
				qc->per=atoi(strtok(NULL," "));
				qc->nr_art=atoi(strtok(NULL," "));
				qc->okc=atoi(strtok(NULL," "));

				if(qc->okc==1)
				{
					fflush(stdin);
					strcpy(qc->numec,strtok(NULL," "));
					qc->annc=atoi(strtok(NULL," "));
					qc->lunac=atoi(strtok(NULL," "));
					qc->zic=atoi(strtok(NULL," "));

				}

				uc->urmc=qc;
				uc=qc;
				uc->urmc=NULL;				
				
			rez2=fgets(liniec,255,h);
			}

		fclose(h);
	}

		
	

	do
	{
		printf("\n\n\n1. Adaugare carte tehnica\n2. Adaugare carte literatura\n3. Adaugare volum de conferinta\n4. Afisarea pe categorii a tuturor cartilor existente\n5. Afisarea in ordine alfabetica a tuturor cartilor\n");
		printf("6. Afisarea tuturor cartilor scrise de un anumit autor\n7. Afisarea tuturor volumelor de conferintã care au o anumita tematica\n8. Imprumutarea unei carti, dupã titlu\n");
		printf("9. Restituirea unei carti imprumutate, dupa titlu\n10. Afisare imprumuturi cu termenul depasit de o anumita data introdusa de la tastatura\n11. Stergerea unei carti dupa titlu\n12. Exit\n");
		printf("\nintroduceti optiunea dorita(sau o valoare mai mare decat 12 pentru a scrie rezultatele in fisier):");
		scanf("%d",&opt);

			switch(opt)
	{
		
		case 1:		u=adaugare_teh(u);
					printf("\n");
					for(s=p;s;s=s->urm)
					printf("%s %s %s %d %d %d %d\n",s->titlu,s->autor,s->lb,s->an,s->nr_ex,s->cota,s->ok);
					break;

		case 2:		ul=adaugare_lit(ul);
					printf("\n");
					for(j=pl;j;j=j->urml)
					printf("%s %s %s %d %d \n",j->titlul,j->autorl,j->tip,j->an_apar,j->okl);
					break;

		case 3:		uc=adaugare_vol_conf(uc);
					printf("\n");
					for(t=pc;t;t=t->urmc)
					printf("%s %s %s %s %d %d %d \n",t->titluc,t->tema,t->org,t->loc,t->per,t->nr_art,t->okc);
					break;

		case 4:		afisare_teh(p);
					afisare_lit(pl);
					afisare_conf(pc);
					break;

		case 5:		i=0;
					q=p;
					while(q)
					{
						i++;
						strcpy(v[i],q->titlu);
						q=q->urm;
					}

					ql=pl;
					while(ql)
					{
						i++;
						strcpy(v[i],ql->titlul);
						ql=ql->urml;
					}

					qc=pc;
					while(qc)
					{
						i++;
						strcpy(v[i],qc->titluc);
						qc=qc->urmc;
					}
					
					afisare_ordonat_tot(v,i);
					break;

		case 6:		printf("\nintroduceti nume autor:");
					fflush(stdin);
					gets(caut_autor);
					printf("\nCartile tehnice scrise de acest autor sunt:\n\n");
					cautare_teh(p,caut_autor);
					printf("\nCartile de literatura scrise de acest autor sunt:\n\n");
					cautare_lit(pl,caut_autor);
					break;

		case 7:		printf("\nintroduceti tematica dorita:");
					fflush(stdin);
					gets(tematica);
					printf("Volumele cu acesta tematica sunt:\n\n");
					cautare_tematica(pc,tematica);
					break;

		case 8:		printf("\nintroduceti titlul cartii pe care doriti sa o imprumutati:");
					fflush(stdin);
					gets(tit);

					q=(teh*)malloc(sizeof(teh));					
					q=imprumut_teh(p,tit);

					if(q==NULL) printf("Cartea tehnica cu acest titlu este deja imprumutata sau nu exista.");
					else
					{ 
					printf("\nDupa imprumut, lista cartilor tehnice este:\n\n");
						while(q)
						{
						if(q->ok==1)
						printf("	-%s %s %s %d %d %d %d %s %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok,q->nume,q->ann,q->luna,q->zi);
						else printf("	-%s %s %s %d %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok);
						q=q->urm;
						}
					}

					ql=(lit*)malloc(sizeof(lit));
					ql=imprumut_lit(pl,tit);

					if(ql==NULL) printf("\nCartea de literatura cu acest titlu este deja imprumutata sau nu exista.");
					else
					{
						printf("\nDupa imprumut,lista cartilor de literatura este:\n\n");
							while(ql)
							{
								if(ql->okl==1)
									printf("	-%s %s %s %d %d %s %d %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl,ql->numel,ql->annl,ql->lunal,ql->zil);
								else printf("	-%s %s %s %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl);
								ql=ql->urml;
							}
					}

					qc=(conf*)malloc(sizeof(conf));
					qc=imprumut_conf(pc,tit);

					if(qc==NULL) printf("\nVolumul este deja imprumutat sau nu exista volum cu acest titlu.");
					else
					{
						printf("\nDupa imprumut, lista volumelor este:\n\n");
						while(qc)
							{
								if(qc->okc==1)
									printf("	-%s %s %s %s %d %d %d %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc,qc->numec,qc->annc,qc->lunac,qc->zic);
								else printf("	-%s %s %s %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc);
								qc=qc->urmc;
							}
					}


					break;

		case 9:		printf("\nintroduceti titlu carte petru restituire:");
					fflush(stdin);
					gets(titl);
					q=(teh*)malloc(sizeof(teh));
					q=restituire_teh(p,titl);

					if(q==NULL) printf("\nCartea tehnica cu titlul '%s'nu este imprumutata sau nu exista.",titl);
					else
					{
						printf("\nDupa restituire, lista cartilor tehnice este:\n\n");
						while(q)
						{
						if(q->ok==1)
						printf("	-%s %s %s %d %d %d %d %s %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok,q->nume,q->ann,q->luna,q->zi);
						else printf("	-%s %s %s %d %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok);
						q=q->urm;
						}
					}

					ql=(lit*)malloc(sizeof(lit));
					ql=restituire_lit(pl,titl);

					if(ql==NULL) printf("\nCartea de literatura cu titlul '%s'nu e imprumutata sau nu exista.",titl);
					else
					{
						printf("\nDupa restituire,lista cartilor de literatura este:\n\n");
							while(ql)
							{
								if(ql->okl==1)
									printf("	-%s %s %s %d %d %s %d %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl,ql->numel,ql->annl,ql->lunal,ql->zil);
								else printf("	-%s %s %s %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl);
								ql=ql->urml;
							}
					}

					qc=(conf*)malloc(sizeof(conf));
					qc=restituire_conf(pc,titl);

					if(qc==NULL) printf("\nVolumul cu titlul '%s' nu a fost imprumutat sau nu exista.",titl);
					else
					{
						printf("\nDupa restituire, lista volumelor este:\n\n");
						while(qc)
							{
								if(qc->okc==1)
									printf("	-%s %s %s %s %d %d %d %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc,qc->numec,qc->annc,qc->lunac,qc->zic);
								else printf("	-%s %s %s %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc);
								qc=qc->urmc;
							}
					}
					
					break;

		case 10:	printf("\nan:");
					scanf("%d",&a);
					printf("luna:");
					scanf("%d",&l);
					printf("zi:");
					scanf("%d",&z);
					afisare_imprumut_teh(p,a,l,z);
					afisare_imprumut_lit(pl,a,l,z);
					afisare_imprumut_conf(pc,a,l,z);
					break;

		case 11:	printf("\ntitlul cartii pe care doriti sa o stergeti:");
					fflush(stdin);
					gets(tt);
					printf("\nDupa stergere:\n");


					if(caut_teh(p,u,tt))
					{
						p=stergere_teh(p,u,tt);
						for(q=p;q;q=q->urm)
						printf("	-%s %s %s %d %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok);
					}

					if(caut_lit(pl,ul,tt))
					{
						pl=stergere_lit(pl,ul,tt);					
						for(ql=pl;ql;ql=ql->urml)
						printf("	-%s %s %s %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl);
					}

					if(caut_conf(pc,uc,tt))
					{
						pc=stergere_conf(pc,uc,tt);
						for(qc=pc;qc;qc=qc->urmc)
						printf("	-%s %s %s %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc);
					}

					break;

		case 12:	exit(0);
					

		default: printf("Nu ati introdus o optiune valida.\n");
	}
	
	}while(opt<=11);

						q=p;
						fprintf(fo,"Rezultate carti tehnice:\n\n");
						while(q)
						{
							
						if(q->ok==1)
						fprintf(fo,"%s %s %s %d %d %d %d %s %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok,q->nume,q->ann,q->luna,q->zi);
						else fprintf(fo,"%s %s %s %d %d %d %d\n",q->titlu,q->autor,q->lb,q->an,q->nr_ex,q->cota,q->ok);
						
							q=q->urm;
						}

	
						ql=pl;
						fprintf(fo,"\nRezultate literatura:\n\n");
						while(ql)
							{
								if(ql->okl==1)
									fprintf(fo,"%s %s %s %d %d %s %d %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl,ql->numel,ql->annl,ql->lunal,ql->zil);
								else fprintf(fo,"%s %s %s %d %d\n",ql->titlul,ql->autorl,ql->tip,ql->an_apar,ql->okl);
								ql=ql->urml;
							}

						
						qc=pc;
						fprintf(fo,"\nRezultate volume conferinta:\n\n");
						while(qc)
							{
								if(qc->okc==1)
									fprintf(fo,"%s %s %s %s %d %d %d %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc,qc->numec,qc->annc,qc->lunac,qc->zic);
								else fprintf(fo,"%s %s %s %s %d %d %d\n",qc->titluc,qc->tema,qc->org,qc->loc,qc->per,qc->nr_art,qc->okc);
								qc=qc->urmc;
						}
						
						
	fclose(fo);		
	getch();	
	return 0;
}