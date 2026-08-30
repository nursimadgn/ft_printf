# VARIADIC FUNCTION
değişken sayıda argüman alan fonksiyonlar genellikle fonksiyon bildiriminde üç nokta (…) (ellipsis)
*#include <stdarg.h> kullanılır* (Provides macros for handling variadic arguments)
* va_list(pdf'te yok?)
* va_start
* va_arg
* va_end
* va_copy
https://cppreference.com/c/variadic
https://cppreference.com/c/language/variadic
https://medium.com/@sddkal/c-cpp-de%C4%9Fi%C5%9Fken-say%C4%B1da-arg%C3%BCman-alan-fonksiyonlar-e8eae4c0e2d6

exp code
```c
#include <stdio.h>
#include <stdarg.h>

int myMaxFunc(int num_args, ...);

int main(){

    int myMaxVar = myMaxFunc(4, 14, 89, 12, 56);

    printf("Max number is: %d\n", myMaxVar);

    return 0;
}

int myMaxFunc(int num_args, ...){

    va_list args;
    
    va_start(args, num_args);

    int max_num = 0;

    for (int i=0; i<num_args; i++){
        int x = va_arg(args, int); 
        if (i==0){ 
            max_num = x; 
        } else if (x > max_num) {
            max_num = x;
        }
    }

    va_end(args);

    return max_num;
}
```
## Code Explanation
### 1. Header Files

* #include <stdio.h>: Provides the printf() function for output.
* #include <stdarg.h>: Provides macros for handling variadic arguments (va_list, va_start, va_arg, and va_end).

### 2. Main Function

calls the myMaxFunc function with four integer arguments: 14, 89, 12, 56.
stores the maximum value returned by myMaxFunc in the variable myMaxVar.
prints the maximum value.

### 3. Variadic Function

#### **definition**: int myMaxFunc(int num_args, ...):
the first parameter, num_args, specifies the number of arguments passed to the function.
the ... syntax indicates that the function can accept a variable number of additional arguments.
#### **implementation**:
A va_list variable is declared to access the variadic arguments.
va_start(args, num_args) initializes the va_list to access the arguments.
A loop iterates through the arguments using va_arg(args, int) to fetch each argument as an integer.
Compares each argument to determine the maximum value.
va_end(args) is called to clean up the va_list after processing.

### 4. Output

Max number is: 89

### Conclusion

This program illustrates the power of variadic functions in C, which allow developers to create flexible functions that can handle an arbitrary number of arguments. Variadic functions are widely used in standard libraries, such as printf(), for implementing variable-length parameter lists. Understanding and using variadic functions is essential in scenarios where the number of inputs may vary at runtime, making the code more general and adaptable. However, developers must carefully manage argument types and memory to avoid errors or undefined behavior.

--
va_arg hafızayı (stack) doğrusal olarak tarar. Fonksiyona parametreleri hangi sıra ile verdiyseniz, tam olarak o sıra ile okumak zorundasınız.

--
Bellekteki "Kayma" Mantığı (Stack Mechanism)Siz fonksiyona argümanları gönderdiğinizde, bu argümanlar bellekte (Stack adı verilen bölgede) yan yana dizilirler.Format Dizesi Adresi: İlk olarak tırnak içindeki metnin bellekteki adresi koyulur.va_start Komutu: Bilgisayara "Format dizesinin bittiği yere git, variadic argümanların başladığı ilk adresi (işaretçiyi) tut" der.va_arg(args, int) Komutu: Bilgisayara şu emri verir:"Şu an durduğun adresten itibaren bir int boyutu kadar (genellikle 4 bayt) ileri kay.""O kaydığın yerdeki veriyi oku ve bana getir."va_arg(args, double) Komutu:"Şimdi de durduğun yerden bir double boyutu kadar (8 bayt) ileri kay ve oradaki veriyi oku


--------
# Printf working prencipe

cspdiuxX% sadece bunlar

printf'in sözdizimi · Başarılı yürütme sonrasında yazdırılan karakter sayısını döndürür. · Bir hata oluşursa, negatif bir değer döndürülür.

Özetle printf fonksiyonun üç özelliği bulunmakta:

1- Ekrana yazı yazması.

2- Return değeri olması.

3- Parametre alan bir fonksiyon olması.

# register mantığı:
//



# hatalarım

va_start sadece bir kez, fonksiyonun başında çağrılmalıdır. Döngü içinde veya başka fonksiyonlara argüman geçilirken (va_start(args, first)) tekrar çağrılması tanımsız davranışa (undefined behavior) veya derleme hatalarına yol açar.


# notlar %i ve %d üzerine

C dilinde (ve printf/scanf gibi C standart kütüphane fonksiyonlarında) %d ve %i, tamsayı türleri için dönüştürme belirleyicileridir, ancak iki bağlamda farklı davranırlar: printf (çıktı) ve scanf (girdi).

printf (çıktı)

%d ve %i eşdeğerdir.
Her iki yöntem de işaretli bir tamsayıyı 10 tabanında biçimlendirir ve değeri aynı şekilde yazdırır.
Örnek: printf("%d %i", 10, 10); "10 10" yazdırır.
scanf (giriş)

Davranış, giriş dizesinin nasıl yorumlandığına bağlı olarak farklılık gösterir:
%d: isteğe bağlı bir işareti okur ve rakamları yalnızca ondalık sayı olarak yorumlar.
Örnek: "%d" ile "012" girilir → sonuç 12 olur.
%i: isteğe bağlı bir işareti okur, ardından tabanı otomatik olarak algılar:
"0x" veya "0X" öneki → onaltılık sistem.
Önek "0" (ardından 'x' gelmeyen) → sekizlik sistem.
Aksi takdirde → ondalık sayı.
Örnek: "%i" ile "012" girişi → değer 10 (sekizlik 12 = ondalık 10); "0x10" girişi → 16.
Diğer notlar

Her zamanki gibi, eşleşen yazı tipi genişlik değiştiricilerini kullanın: uzun yazı tipleri için %ld/%li, kısa yazı tipleri için %hd/%hi vb.
Daha güvenli giriş için, scanf'in %i otomatik algılamasına güvenmek yerine, açık taban ayrıştırmayı (base ile strtol) tercih edin.
Pratikte, ondalık girdi beklediğinizde çıktı için ve scanf için %d kullanın; scanf'te %i'yi yalnızca C tarzı değişmez yorumlama (sekizli/onaltılık/ondalık) istediğinizde kullanın.
Tanımlanan davranış, Mayıs 2024'e kadar mevcut olan bilgiler de dahil olmak üzere C standardını yansıtmaktadır.



return (nil)