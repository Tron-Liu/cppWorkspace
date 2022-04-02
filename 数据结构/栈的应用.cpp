#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"
#include "SqStack1.h"

void  trans(char *exp, char postexp[])		//���������ʽexpת���ɺ�׺���ʽpostexp
{
	char e;
	SqStack *Optr;										//���������ջָ��
	InitStack(Optr);									//��ʼ�������ջ
	int i = 0;												//i��Ϊpostexp���±�
	while (* exp!='\0')								//exp���ʽδɨ����ʱѭ��
	{
		switch (*exp)
		{
		case '(':												//�ж�Ϊ������
			Push(Optr, '(');								//�����Ž�ջ
			exp++;											//����ɨ������Ԫ��
			break;
		case ')':												//�ж�Ϊ������
			Pop(Optr, e);								//��ջԪ��e
			while (e != '(')								//��Ϊ������ʱѭ��
			{
				postexp[i++] = e;					//��e��ŵ�postexp��
				Pop(Optr, e);							//������ջԪ��e
			}
			exp++;											//����ɨ������Ԫ��
			break;
		case '+':
		case '-':												//�ж�Ϊ�ӻ����
			while (!StackEmpty(Optr))			//ջ����ʱѭ��
			{
				GetTop(Optr, e);						//ȡջ��Ԫ��
				if (e != '(')									//e����������
				{
					postexp[i++] = e;				//��e��ŵ�postexp��
					Pop(Optr, e);						//��ջԪ��
				}
				else											//��������ʱ�˳�ѭ��
					break;
			}
			Push(Optr, *exp);							//��'+'��'-'��ջ
			exp++;											//����ɨ�������ַ�
			break;
		case '*':
		case '/':												//�ж�Ϊ'*'��'/'��
			while (!StackEmpty(Optr))			//ջ����ʱѭ��
			{
				GetTop(Optr, e);						//ȡջ��Ԫ��
				if (e == '*' || e == '/')				//��ջ��Ԫ��'*'��'/'�������ջ����ŵ�postexp��
				{
					postexp[i++] = e;				//��e��ŵ�postexp��
					Pop(Optr, e);						//��ջeԪ��
				}
				else											//eΪ��'*'��'/'�����ʱ�˳�ѭ��
					break;
			}
			Push(Optr, *exp);							//��'*'��'/'��ջ
			exp++;											//����ɨ������Ԫ��
			break;
		default:											//���������ַ�
			while (*exp>='0'&&*exp<='9')	//�ж�Ϊ�����ַ�
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';						//��#��ʶһ�����ִ�����
		}
	}
	while (!StackEmpty(Optr))					//��ʱexpɨ����ϣ�ջ����ʱѭ��
	{
		Pop(Optr, e);									//��ջԪ��e
		postexp[i++] = e;							//��e��ŵ�postexp��
	}
	postexp[i] = '\0';									//��postexp���ʽ��ӽ�����ʶ
	DestroyStack(Optr);								//����ջ
}

double compavalue(char *postexp)		//�����׺���ʽ��ֵ
{
	double d, a, b, c, e;
	SqStack1 *Opnd;									//���������ջ
	InitStack1(Opnd);									//��ʼ��������ջ
	while (*postexp != '\0')						//postexp�ַ���δɨ�����
	{
		switch (*postexp)
		{
		case '+':											//�ж�Ϊ'+'��
			Pop1(Opnd, a);							//��ջԪ��a
			Pop1(Opnd, b);							//��ջԪ��b
			c = b + a;										//����c
			Push1(Opnd, c);							//��������c��ջ
			break;
		case '-':												//�ж�Ϊ'-'��
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b - a;
			Push1(Opnd, c);
			break;
		case '*':											//�ж�Ϊ'*'��
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			c = b * a;
			Push1(Opnd, c);
			break;
		case '/':												//�ж�Ϊ'/'��
			Pop1(Opnd, a);
			Pop1(Opnd, b);
			if (a != 0)
			{
				c = b / a;
				Push1(Opnd, c);
				break;
			}
			else
			{
				printf("\n\t�������\n");
				exit(0);										//�쳣�˳�
			}
			break;
		default:											//���������ַ�
			d = 0;											//�������������ַ�ת���ɶ�Ӧ����ֵ��ŵ�d��
			while (*postexp>='0' && *postexp<='9')		//�ж�Ϊ�����ַ�
			{
				d = 10 * d + *postexp - '0';
				postexp++;
			}
			Push1(Opnd, d);							//����ֵd��ջ
			break;
		}
		postexp++;										//�������������ַ�
	}
	GetTop1(Opnd, e);								//ȡջ��Ԫ��e
	DestroyStack1(Opnd);							//����ջ
	return e;												//����e
}

int main()
{
	char exp[] = "(56-20)/(4+2)";									//�ɽ�exp��Ϊ��������
	char postexp[MaxSize];
	trans(exp, postexp);													//��expת��Ϊpostexp
	printf("��׺���ʽ:%s\n", exp);									//���exp
	printf("��׺���ʽ:%s\n", postexp);							//���postexp
	printf("���ʽ��ֵ:%g\n", compavalue(postexp));	//��postexp��ֵ�����
	system("pause");
	return 1;
}