# Maintainer: GG weebcyberpunk@gmail.com
pkgname=blin
pkgver=1.0.0
pkgrel=1
pkgdesc="Breaks lines in last-blank."
arch=("x86_64")
url="https://www.github.com/weebcyberpunk/blin"
license=('MIT')
provides=(blin)
source=("git+$url")
md5sums=('SKIP')

build() {
	cd "$pkgname"
	gcc main.c -o blin
}

package() {
	cd "$pkgname"
	install -Dm755 blin $pkgdir/usr/bin/blin
	install -Dm644 blin1.gz $pkgdir/usr/share/man/man1/blin1.gz
}
