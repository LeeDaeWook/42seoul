curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

cd /var/www
wp core download --allow-root --path=/var/www

cp /tmp/wp-config.php /var/www

wp core install --allow-root --path=/var/www \
								--url=daewoole.42.fr \
								--title=Inception \
								--admin_user=daewoole \
								--admin_password=4242 \
								--admin_email=daewoole@student.42seoul.kr \
								--skip-email

wp user create daewoole daewoole@student.student.kr \
				--allow-root --path=/var/www \
				--role=author \
				--user_pass=4242

exec php-fpm8 -F