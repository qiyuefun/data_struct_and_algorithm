   //��������ʵ�ֵ�˳��ջ
 public class ArrayStack{
	private String[] item; //����
	private int count;     //ջ��Ԫ�ظ���
	private int n;         //ջ�Ĵ�С
	
	// ��ʼ�����飬����һ����СΪn������ռ�
	public ArrayStack(int n ){
		this.items = new String[n];
		this.n = n;
		this.count = 0;
		
	}
	
	// ��ջ
	public boolean push(String item){
		// ����ռ䲻���ˣ�ֱ�ӷ��� false ��ջʧ��
		if(count == n) return false;
			//��item�ŵ��±�Ϊcount��λ�ã�����count
			items[count]  = item;
			++count;
			return true;
	}
	//��ջ 
	public String pop(){
		// ջΪ�գ���ֱ�ӷ���null
		if(count == 0 ) return null;
			// �����±�Ϊcount -1 ������Ԫ�أ�����ջ��Ԫ�ظ���count��һ
			String tmp = items[count - 1];
			--count;
			return tmp;
	}
 }
