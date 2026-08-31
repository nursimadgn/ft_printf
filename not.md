# 42 ft_printf Çalışma Notları

---

## 1. Variadic Functions (Değişken Sayıda Argüman Alan Fonksiyonlar)

C dilinde parametre sayısı önceden sabitlenmemiş fonksiyonlar bildirimde üç nokta (`...` / ellipsis) ile tanımlanır. Bu mekanizmayı yönetmek için `<stdarg.h>` kütüphanesindeki makrolar kullanılır.

### Temel `<stdarg.h>` Bileşenleri
* **`va_list`**: Argüman listesinin bellekteki (Stack) konumunu tutan işaretçi tipi.
* **`va_start(args, last_arg)`**: `va_list` işaretçisini ilk değişken argümanın adresine odaklar.
* **`va_arg(args, type)`**: İşaretçinin bulunduğu adresten verilen `type` türü kadar bayt okur ve işaretçiyi o türün boyutu kadar ileri öteler.
* **`va_end(args)`**: Argüman listesini temizler ve sonlandırır.
* **`va_copy(dest, src)`**: Mevcut bir argüman listesini başka bir `va_list` nesnesine kopyalar.

---

## 2. Bellekteki "Kayma" Mantığı (Stack Mechanism)

Fonksiyona parametreler gönderildiğinde, bu değerler çağrı yığınına (Call Stack) sırayla yerleşir:

1. **Format Dizesi Adresi:** İlk olarak format metninin bellekteki adresi yığına girer.
2. **`va_start` Komutu:** Bilgisayara *"Format dizesinin bittiği yere git, ilk değişken argümanın adresini tut"* der.
3. **`va_arg(args, int)` Komutu:** *"Mevcut adresten 4 bayt (`int`) oku ve işaretçiyi 4 bayt ileri kaydır."*
4. **`va_arg(args, double)` Komutu:** *"Mevcut adresten 8 bayt (`double`) oku ve işaretçiyi 8 bayt ileri kaydır."*

> ⚠️ **Doğrusal Okuma Kuralı:** `va_arg` yığını doğrusal tarar. Parametreler fonksiyona hangi sıra ile verildiyse tam olarak o sıra ile okunmak zorundadır.

---

## 3. Örnek Kod Analizi

```c
#include <stdio.h>
#include <stdarg.h>

int myMaxFunc(int num_args, ...)
{
    va_list args;
    int     max_num;
    int     x;

    va_start(args, num_args);
    for (int i = 0; i < num_args; i++)
    {
        x = va_arg(args, int);
        if (i == 0 || x > max_num)
            max_num = x;
    }
    va_end(args);
    return (max_num);
}

int main(void)
{
    int max = myMaxFunc(4, 14, 89, 12, 56);
    printf("Max number is: %d\n", max); // Çıktı: 89
    return (0);
}
```

### Kodun Çalışma Adımları:
1. `myMaxFunc(4, 14, 89, 12, 56)` çağrılır; `num_args = 4` kaç argüman okunacağını belirtir.
2. `va_start(args, num_args)` ile ilk argümanın (`14`) adresine konumlanılır.
3. Döngü boyunca `va_arg(args, int)` ile sırasıyla `14`, `89`, `12`, `56` değerleri okunur ve en büyüğü belirlenir.
4. `va_end(args)` ile liste kapatılır ve `89` değeri döndürülür.

---

## 4. `ft_printf` Çalışma Prensibi

`printf` fonksiyonunun üç temel özelliği bulunur:
* **Ekrana Yazı Basması:** Format dizesini ve dönüştürülen verileri standart çıktıya yazar.
* **Parametre Alması:** Değişken sayıda parametre kabul eder.
* **Return Değeri Döndürmesi:** Başarılı çalışmada ekrana yazdırılan **toplam karakter sayısını**, hata durumunda negatif bir değer (`-1`) döndürür.

### Zorunlu Dönüştürücüler (`cspdiuxX%`):
* `%c` : Tek bir karakter basar.
* `%s` : Karakter dizisi (string) basar (`NULL` ise `(null)` yazar).
* `%p` : `void *` işaretçi adresini hexadecimal formatta basar (`NULL` durumunda OS standardına göre `(nil)` veya `0x0`).
* `%d` : İşaretli 10 tabanlı tamsayı basar.
* `%i` : 10 tabanında tamsayı basar.
* `%u` : İşaretsiz 10 tabanlı tamsayı basar (`unsigned int`).
* `%x` : 16 tabanlı küçük harfli onaltılık sayı basar (`0123456789abcdef`).
* `%X` : 16 tabanlı büyük harfli onaltılık sayı basar (`0123456789ABCDEF`).
* `%%` : `%` karakterinin kendisini basar.

---

## 5. `%d` ve `%i` Arasındaki Fark

| Bağlam | `%d` Davranışı | `%i` Davranışı |
| :--- | :--- | :--- |
| **`printf` (Çıktı)** | İşaretli tamsayıyı 10 tabanında basar. | `%d` ile tamamen eşdeğerdir, 10 tabanında basar. |
| **`scanf` (Girdi)** | Girdiyi her zaman 10 tabanında yorumlar (`"012"` $\rightarrow$ `12`). | Tabanı otomatik algılar (`0x` $\rightarrow$ hex, `0` $\rightarrow$ octal, aksi $\rightarrow$ decimal). |

---

## 6. Sık Yapılan Hatalar & Dikkat Edilmesi Gerekenler

* **Tekrarlanan `va_start` Çağrısı:** `va_start` fonksiyonun başında yalnızca bir kez çağrılmalıdır. Döngü içinde veya yardımcı fonksiyonlara argüman aktarırken tekrar çağrılması tanımsız davranışa (Undefined Behavior) yol açar.
* **Register Mantığı:** Çağrı standartlarında (calling convention) ilk birkaç argüman yazmaçlara (registers) yerleşebilir, ardından stack kullanılır; `<stdarg.h>` makroları bu karmaşayı soyutlar.
* **Pointer Dönüşümü:** `%p` adres formatlamasında sistem mimarisine (64-bit: `unsigned long` / `uintptr_t`) dikkat edilmelidir.

---

## 7. Kaynaklar & Test Araçları

* [C Variadic Functions - cppreference.com](https://cppreference.com/c/variadic)
* [C Language Variadic Arguments - cppreference.com](https://cppreference.com/c/language/variadic)
* [C/C++ Değişken Sayıda Argüman Alan Fonksiyonlar - Medium](https://medium.com/@sddkal/c-cpp-de%C4%9Fi%C5%9Fken-say%C4%B1da-arg%C3%BCman-alan-fonksiyonlar-e8eae4c0e2d6)
* [Tripouille/printfTester](https://github.com/Tripouille/printfTester)