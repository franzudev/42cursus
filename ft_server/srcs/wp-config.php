<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', 'utf8mb4_unicode_ci' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'ztp<j>BUXk6Dv^yM+OM)4Fu5E)z4=P%L|}o8F+x`8T7}?n-,Zue~QTmFp)/a+`EB');
define('SECURE_AUTH_KEY',  'r;<PbN[SK`{G~~,M);O0#BTmAW$||h#d:~BN(zx<NyR{HGMTxvbf4_xdpmvsk%MX');
define('LOGGED_IN_KEY',    'C#|r7OH+]6FKBY B8Jm|95Q2$5h$NJ0Y?2 N4<fGCtVU+i?jb1?-3WDq5R`r6u[u');
define('NONCE_KEY',        '4e:y^+F:H;SW$K(;z@T.-s{E7:Kr[a0${P0fN,Yn&hm.V5FImn(jR&$|9a[~,WFh');
define('AUTH_SALT',        'E<BIu:5qq?Z4/Zb]MN*3b(ME5Gk#pAf6S=r+LR(`EU$-h6JX5MWPf+Y:+W2p[xU3');
define('SECURE_AUTH_SALT', '_o%P,D|_?lq$DLK;4;8Y3})i!6{8Vp-!g$vN|PA(NR!_-MJ8x~wjlsah<wr%f+p ');
define('LOGGED_IN_SALT',   'HKh@DtUT!|R)WOT6i?C}`#y;I]&oC+kh<@tNDoTe=pd|E ]^&y/t(xsjT<;X0z;~');
define('NONCE_SALT',       '8GEN9f-ke9(_9BYx4riSWvWJx+xG_k$qxpSOR{&rEc0CEd[$;=!;@~| ]muC@x]~');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';