# -*- coding: gbk -*-
import sys
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

def draw_chart(users, borrow_counts):
    # ����ƽ����������
    average_borrow = sum(borrow_counts) / len(borrow_counts)
    
    # ����һ��ͼ�δ��ڣ�����Ϊ1��2�е���ͼ
    fig, axs = plt.subplots(1, 2, figsize=(16, 6))
    
    # ��һ����ͼ������ͼ
    axs[0].bar(users, borrow_counts, color='skyblue')
    axs[0].set_xlabel('�û�')
    axs[0].set_ylabel('��������')
    axs[0].set_title('�û���������ͼ��')
    axs[0].tick_params(axis='x', rotation=45)
    axs[0].grid(axis='y', linestyle='--', alpha=0.7)
    axs[0].yaxis.set_major_locator(ticker.MaxNLocator(integer=True))
    axs[0].axhline(average_borrow, color='r', linestyle='--', label=f'ƽ����������: {average_borrow:.2f}')
    axs[0].legend()
    
    # ������ͼ��ÿ��������������ݱ�ǩ
    for i, count in enumerate(borrow_counts):
        axs[0].text(i, count + count * 0.05, str(count), ha='center', va='bottom')
    
    # �ڶ�����ͼ����ͼ
    axs[1].pie(borrow_counts, labels=users, autopct='%1.1f%%', startangle=140)
    axs[1].set_title('ÿ���û����ܽ������е�ռ��')
    
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    args = sys.argv[1:]
    users = args[0::2]
    borrow_counts = [int(count) for count in args[1::2]]

    draw_chart(users, borrow_counts)
