**Karma (Hashing) Yöntemiyle Dosya Düzenleme**

Bu ödevdebasit kütüphane katalog sistemi, kova (bucket) boyutu 5 olan karma (hashing) yöntemi kullanılarak uygulanacaktır. Bu uygulamada sadece sistem yöneticisi, sisteme bir kitap kaydı ekleme, var olan bir kitap kaydını sistemden silme ve arama işlemleri yapacaktır. Sistemde ISBN numarası tek başına birincil anahtar olarak kullanılacaktır. Karma yöntemini uygularken şunlara dikkat edilecektir:

1)     Çakışmalarla baş etmek (collision resolution) için ilerlemeli taşma (progressive overflow) yöntemi uygulanacaktır.

2)     Karma fonksiyonu hash(x) = x mod N olup N değeri 41’dir.

3)     Programın her arama işleminden sonra ortalama arama uzunluğu için istatistik tutması sağlanacak ve her kayıt ekleme işleminden sonra karma dosyası yoğunlaşma değeri (packing factor) güncellenecektir.

4)     Arama uzunluğu veya yoğunlaşma değeri dosyanın yeniden düzenlenmesini gerektirecek bir noktaya geldiğinde programın uyarı vermesi sağlanacaktır.

·     Uygulama için “books.txt” dosyası içerisindeki kitap kayıtlarından ISBN, Kitap Adı, Kitap Yazarı ve Fiyat alanları için yine sabit uzunluklu kayıtlar tasarlayınız. 

·     Aynı kayıt uzunluğu için 41x5 kayıt tutabilecek boş bir “booksHash.bin” dosyası oluşturunuz.

·     “books.txt” içerisinden teker teker okuyup oluşturduğunuz sabit uzunluklu kayıtların ISBN numaralarını hash fonksiyonuna koyarak ilgili kaydı “booksHash.bin” dosyası içerisinde hangi ev adresine kaydetmeniz gerektiğini hesaplayınız. İlerlemeli taşma yöntemini kullanarak kaydı dosyaya yerleştiriniz.

·     Kayıt ekleme, kayıt silme ve arama fonksiyonları için benzer şekilde ISBN numaralarını hash fonksiyonuna koyarak tüm ekleme, silme ve arama işlemlerini “booksHash.bin” dosyası içerisinde gerçekleştiriniz.

·        Kayıt eklemede ilgili ev adresinde eğer 1. kova doluysa, 2. kovaya bakılır. 2. kova boşsa kayıt buraya eklenir. Bu da doluysa 3. kovaya bakılır. 5. kovaya kadar bu işleme devam edilir. 5. kova da doluysa ilerlemeli taşma yöntemine göre bir sonraki ev adresine geçilip aynı işleme devam edilir.

·       Arama işlemi için istenen kaydın ISBN’si bulunana veya boş (null) bir değerle karşılaşılana değin ilgili ev adresinde sırayla kovalara bakılır. Kovalar dolu olup hiçbir kovada kayıt bulunamazsa takip eden ev adreslerinde arama işlemine devam edilir.

·       Silme işlemi için istenen kaydı bulmada arama işlemindeki süreç tekrar edilir. Yalnız silinecek kayıt bulununca ISBN’si yerine bir mezar taşı (mesela #) konur. Bu mezar taşı arama süresince aramanın devam etmesi gerektiğine işaret eder.


 

