# Sistem Programlama Odevi 2021

Programın amacı şifresiz girdilerin ve bu girdilere ait huffman kodlarının olduğu yalın haldeki verileri bir dosyaya şifreli hallerini basmak; veya bu yöntemle şifrelenmiş verileri içeren bir text dosyasını okuyarak, şifreli verileri şifresiz halleri ile bir dosyaya yazmaktır.

- Kullanıcı terminalden "kripto -d <giriş_metin> <cikis_metin>" veya "kripto -e <giriş_metin> <cikis_metin>" komutunu girer.
- Öncelikle yapılacak işlemden bağımsız olarak .kilit dosyası okunur.
- Giriş metini okunur.
- Girilen komuttaki 2. argüman "-e" ise şifreleme, "-d" ise şifre çözme işlemi yapılmak üzere ilgili işlemin olduğu kod bloklarına ilerlenir.
  - Şifreleme işlemi yapılacaksa giriş metinindeki kelimeler okunur ve huffman kodu karşılıkları .kilit dosyasında bulunarak her ilgili kelimeye air huffman kodu çıkış metin dosyasına yazılır.
  - Şifre çözme işlemi yapılacaksa giriş metinindeki huffman kodları okunur ve .kilit dosyasında karşılaştırılarak her ilgili huffman kodu için olan kelime çıkış metin dosyasına yazılır.

Kullanılan Teknoloji ve Kütüphaneler:

- C
- Libfdr
  - Fields: Basit değişken işlemleri
  - Jvals : Jenerik yapı oluşturma
  - JRB : Ağaç oluşturma

Komutlar:

- $> kripto -d <giriş_metin> <cikis_metin>
- $> kripto -e <giriş_metin> <cikis_metin>

Eren DEĞİRMENCİ - G181210017
Yasin ÜNAL - G181210071
Berkay ÇETE - G181210020
Rami MUSTAFA - G181210560
