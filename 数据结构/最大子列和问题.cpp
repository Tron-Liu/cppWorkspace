int MaxSubseqSum1(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j, k;
	for(i=0; i<N; i++) {            //i���������λ�� 
		for(j=i; j<N; j++) {        //j�������Ҷ�λ�� 
			ThisSum = 0;
			for(k=i; k<=j; k++) {   //ThisSum�Ǵ�A[i]��A[j]�����к� 
				ThisSum += A[k]; 
			}
			if(ThisSum > MaxSum)    //����յõ���������к͸��� 
				MaxSum = ThisSum;   //���½�� 
		}
	}
	return MaxSum
}

int MaxSubseqSum2(int A[], int N)
{
	int ThisSum, MaxSum = 0;
	int i, j;
	for(i=0; i<N; i++) {         //i��������� 
		ThisSum = 0;             //ThisSum�Ǵ�A[i]��A[j]�����к� 
		for(j=i;j<N;j++) {       //j�������Ҷ� 
			ThisSum += A[j];     //������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�һ��� 
			if(ThisSum > MaxSum) //����յõ���������к͸��� 
				MaxSum = ThisSum;//����½�� 
		}
	}
	return MaxSum;
}

//���ߴ���
int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for(i=0; i<N; i++) {
		ThisSum += A[i];    //�����ۼ� 
		if(ThisSum > MaxSum) MaxSum = ThisSum; //���ָ��������µ�ǰ��� 
		else if(ThisSum < 0)  //�����ǰ���к�Ϊ�� 
			ThisSum = 0;      //�򲻿���ʹ����Ĳ��ֺ��������� 
	}
	return MaxSum;
}
