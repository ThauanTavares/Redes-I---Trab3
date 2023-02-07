#!/usr/bin/python3

import random





def main():
    mensagemEnv="11111111111111111111111111111111"
    mensagemEnv="00000000000000000000000000000000"
    
    mensagemRec=""
    janela=[]
    janelaInter=[]
    aux=[]
    i=0
    tempo=15
    #    janela[i]=mensagemEnv[]
    print("Mensagem Enviada: ", mensagemEnv)
    while(i<32):
        print("\nTEMPO = ",tempo)
        #print("i = ",i)
        nack=-1
        if(i+4<=32):
            janela = mensagemEnv[i:i+4]
        else:
            janela=  mensagemEnv[i:32]  
        janelaInter=janela
        print("\nindice",i,i+3)
        print("\njanela enviada = " , str(janela))
        chance=random.randrange(1,10)
        if(chance <= 5):    
            x=random.randrange(0,len(janela))
            l=list(janelaInter)
            if(l[x]=='1'):
                l[x]='0'
            else:
                l[x]='1'
            janelaInter="".join(l)
            nack=x
        if(nack!= -1):
            i=i+nack
            print("\njanela Recebida = " , str(janelaInter))
            print("nack = ",nack)            
            

            aux=janelaInter[0:nack]
            mensagemRec=str(mensagemRec)+str(aux)
            print("\nACK",i-1) 
            print("\nMensagem Recebida = ", str(mensagemRec))
            nack=-1
            tempo=tempo-1

            
        else:
            i=i+4
            nack=-1
            print("\njanela Recebida = " , str(janelaInter))    
            if(i>32):
                print("ACK",32)
            else:
                print("ACK",i-1)
            mensagemRec=str(mensagemRec)+str(janelaInter)
            print("\nMensagem Recebida = ", str(mensagemRec))

            tempo=tempo-1
        if(tempo==-1):
            print("\nTime Erro\n")
            print("\nENVIAR MENSAGEM NOVAMENTE\n")
            print("\nMensagem Enviada: ", mensagemEnv)


            i=0
            mensagemRec=""
            tempo=15

    print("\nMensagem Recebida Final\n")
    print(str(mensagemRec))
    print("\nMensagem Enviada\n")
    print(mensagemEnv)
    


main()