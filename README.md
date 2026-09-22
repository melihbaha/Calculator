# C Mathematical Expression Evaluator & Parser

C dili ile geliştirilen; tampon bellek (buffer) yönetimi, sözcük çözümleme (tokenization) ve işlem önceliği (operator precedence) algoritmalarını kullanarak karmaşık matematiksel ifadeleri ayrıştıran ve hesaplayan komut satırı uygulaması.

> ⚠️ *Bu proje aktif olarak geliştirilmeye ve genişletilmeye devam etmektedir.*

## 🛠️ Teknik Özellikler & Mimari
- **Buffer Stream Management:** Kullanıcı girdilerini tampon bellek üzerinden güvenli bir şekilde okuma ve işleme.
- **Lexical Tokenization:** Girdi dizisini sayılar, operatörler ve semboller olarak anlamlı simgelere (token) dönüştürme.
- **Precedence Handling:** İşlem önceliği kurallarını ve parantez yapılarını dikkate alan ayrıştırma mantığı.
- **Low-Level C Implementation:** Harici kütüphane bağımlılığı olmadan saf C standart kütüphaneleri ile geliştirilmiş altyapı.

## 🚀 Derleme ve Çalıştırma

```bash
gcc main.c -o calculator
./calculator
