#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

/*** Folder allegro5 ***/



// alcompat.h - Plik1
// ***nie znaleziono żadnej funkcji***

// alinline.h - Plik2
// ***nie znaleziono żadnej funkcji***

// allegro.h - Plik3
// ***nie znaleziono żadnej funkcji***

// allegro5.h - Plik4
// ***nie znaleziono żadnej funkcji***

// allegro_acodec.h - Plik5
bool al_init_acodec_addon( void );
uint32_t al_get_allegro_acodec_version( void );


// allegro_audio.h - Plik6
ALLEGRO_SAMPLE * al_create_sample( void * buf,
unsigned int samples, unsigned int freq, ALLEGRO_AUDIO_DEPTH depth,
ALLEGRO_CHANNEL_CONF chan_conf, bool free_buf );
void al_destroy_sample( ALLEGRO_SAMPLE * spl );
ALLEGRO_SAMPLE_INSTANCE * al_create_sample_instance(
ALLEGRO_SAMPLE * data );
void al_destroy_sample_instance(
ALLEGRO_SAMPLE_INSTANCE * spl );
unsigned int al_get_sample_frequency( const ALLEGRO_SAMPLE * spl );
unsigned int al_get_sample_length( const ALLEGRO_SAMPLE * spl );
ALLEGRO_AUDIO_DEPTH al_get_sample_depth( const ALLEGRO_SAMPLE * spl );
ALLEGRO_CHANNEL_CONF al_get_sample_channels( const ALLEGRO_SAMPLE * spl );
void * al_get_sample_data( const ALLEGRO_SAMPLE * spl );
unsigned int al_get_sample_instance_frequency( const ALLEGRO_SAMPLE_INSTANCE * spl );
unsigned int al_get_sample_instance_length( const ALLEGRO_SAMPLE_INSTANCE * spl );
unsigned int al_get_sample_instance_position( const ALLEGRO_SAMPLE_INSTANCE * spl );
float al_get_sample_instance_speed( const ALLEGRO_SAMPLE_INSTANCE * spl );
float al_get_sample_instance_gain( const ALLEGRO_SAMPLE_INSTANCE * spl );
float al_get_sample_instance_pan( const ALLEGRO_SAMPLE_INSTANCE * spl );
float al_get_sample_instance_time( const ALLEGRO_SAMPLE_INSTANCE * spl );
ALLEGRO_AUDIO_DEPTH al_get_sample_instance_depth( const ALLEGRO_SAMPLE_INSTANCE * spl );
ALLEGRO_CHANNEL_CONF al_get_sample_instance_channels( const ALLEGRO_SAMPLE_INSTANCE * spl );
ALLEGRO_PLAYMODE al_get_sample_instance_playmode( const ALLEGRO_SAMPLE_INSTANCE * spl );
bool al_get_sample_instance_playing( const ALLEGRO_SAMPLE_INSTANCE * spl );
bool al_get_sample_instance_attached( const ALLEGRO_SAMPLE_INSTANCE * spl );
bool al_set_sample_instance_position( ALLEGRO_SAMPLE_INSTANCE * spl, unsigned int val );
bool al_set_sample_instance_length( ALLEGRO_SAMPLE_INSTANCE * spl, unsigned int val );
bool al_set_sample_instance_speed( ALLEGRO_SAMPLE_INSTANCE * spl, float val );
bool al_set_sample_instance_gain( ALLEGRO_SAMPLE_INSTANCE * spl, float val );
bool al_set_sample_instance_pan( ALLEGRO_SAMPLE_INSTANCE * spl, float val );
bool al_set_sample_instance_playmode( ALLEGRO_SAMPLE_INSTANCE * spl, ALLEGRO_PLAYMODE val );
bool al_set_sample_instance_playing( ALLEGRO_SAMPLE_INSTANCE * spl, bool val );
bool al_detach_sample_instance( ALLEGRO_SAMPLE_INSTANCE * spl );
bool al_set_sample( ALLEGRO_SAMPLE_INSTANCE * spl, ALLEGRO_SAMPLE * data );
ALLEGRO_SAMPLE * al_get_sample( ALLEGRO_SAMPLE_INSTANCE * spl );
bool al_play_sample_instance( ALLEGRO_SAMPLE_INSTANCE * spl );
bool al_stop_sample_instance( ALLEGRO_SAMPLE_INSTANCE * spl );
ALLEGRO_AUDIO_STREAM * al_create_audio_stream( size_t buffer_count,
unsigned int samples, unsigned int freq,
ALLEGRO_AUDIO_DEPTH depth, ALLEGRO_CHANNEL_CONF chan_conf );
void al_destroy_audio_stream( ALLEGRO_AUDIO_STREAM * stream );
void al_drain_audio_stream( ALLEGRO_AUDIO_STREAM * stream );
unsigned int al_get_audio_stream_frequency( const ALLEGRO_AUDIO_STREAM * stream );
unsigned int al_get_audio_stream_length( const ALLEGRO_AUDIO_STREAM * stream );
unsigned int al_get_audio_stream_fragments( const ALLEGRO_AUDIO_STREAM * stream );
unsigned int al_get_available_audio_stream_fragments( const ALLEGRO_AUDIO_STREAM * stream );
float al_get_audio_stream_speed( const ALLEGRO_AUDIO_STREAM * stream );
float al_get_audio_stream_gain( const ALLEGRO_AUDIO_STREAM * stream );
float al_get_audio_stream_pan( const ALLEGRO_AUDIO_STREAM * stream );
ALLEGRO_CHANNEL_CONF al_get_audio_stream_channels( const ALLEGRO_AUDIO_STREAM * stream );
ALLEGRO_AUDIO_DEPTH al_get_audio_stream_depth( const ALLEGRO_AUDIO_STREAM * stream );
ALLEGRO_PLAYMODE al_get_audio_stream_playmode( const ALLEGRO_AUDIO_STREAM * stream );
bool al_get_audio_stream_playing( const ALLEGRO_AUDIO_STREAM * spl );
bool al_get_audio_stream_attached( const ALLEGRO_AUDIO_STREAM * spl );
void * al_get_audio_stream_fragment( const ALLEGRO_AUDIO_STREAM * stream );
bool al_set_audio_stream_speed( ALLEGRO_AUDIO_STREAM * stream, float val );
bool al_set_audio_stream_gain( ALLEGRO_AUDIO_STREAM * stream, float val );
bool al_set_audio_stream_pan( ALLEGRO_AUDIO_STREAM * stream, float val );
bool al_set_audio_stream_playmode( ALLEGRO_AUDIO_STREAM * stream, ALLEGRO_PLAYMODE val );
bool al_set_audio_stream_playing( ALLEGRO_AUDIO_STREAM * stream, bool val );
bool al_detach_audio_stream( ALLEGRO_AUDIO_STREAM * stream );
bool al_set_audio_stream_fragment( ALLEGRO_AUDIO_STREAM * stream, void * val );
bool al_rewind_audio_stream( ALLEGRO_AUDIO_STREAM * stream );
bool al_seek_audio_stream_secs( ALLEGRO_AUDIO_STREAM * stream, double time );
double al_get_audio_stream_position_secs( ALLEGRO_AUDIO_STREAM * stream );
double al_get_audio_stream_length_secs( ALLEGRO_AUDIO_STREAM * stream );
bool al_set_audio_stream_loop_secs( ALLEGRO_AUDIO_STREAM * stream, double start, double end );
ALLEGRO_EVENT_SOURCE * al_get_audio_stream_event_source( ALLEGRO_AUDIO_STREAM * stream );
ALLEGRO_MIXER * al_create_mixer( unsigned int freq,
ALLEGRO_AUDIO_DEPTH depth, ALLEGRO_CHANNEL_CONF chan_conf );
void al_destroy_mixer( ALLEGRO_MIXER * mixer );
bool al_attach_sample_instance_to_mixer(
ALLEGRO_SAMPLE_INSTANCE * stream, ALLEGRO_MIXER * mixer );
bool al_attach_audio_stream_to_mixer( ALLEGRO_AUDIO_STREAM * stream,
ALLEGRO_MIXER * mixer );
bool al_attach_mixer_to_mixer( ALLEGRO_MIXER * stream,
ALLEGRO_MIXER * mixer );
bool al_set_mixer_postprocess_callback(
ALLEGRO_MIXER * mixer,
void( * cb )( void * buf, unsigned int samples, void * data ),
void * data );
unsigned int al_get_mixer_frequency( const ALLEGRO_MIXER * mixer );
ALLEGRO_CHANNEL_CONF al_get_mixer_channels( const ALLEGRO_MIXER * mixer );
ALLEGRO_AUDIO_DEPTH al_get_mixer_depth( const ALLEGRO_MIXER * mixer );
ALLEGRO_MIXER_QUALITY al_get_mixer_quality( const ALLEGRO_MIXER * mixer );
float al_get_mixer_gain( const ALLEGRO_MIXER * mixer );
bool al_get_mixer_playing( const ALLEGRO_MIXER * mixer );
bool al_get_mixer_attached( const ALLEGRO_MIXER * mixer );
bool al_set_mixer_frequency( ALLEGRO_MIXER * mixer, unsigned int val );
bool al_set_mixer_quality( ALLEGRO_MIXER * mixer, ALLEGRO_MIXER_QUALITY val );
bool al_set_mixer_gain( ALLEGRO_MIXER * mixer, float gain );
bool al_set_mixer_playing( ALLEGRO_MIXER * mixer, bool val );
bool al_detach_mixer( ALLEGRO_MIXER * mixer );
ALLEGRO_VOICE * al_create_voice( unsigned int freq,
ALLEGRO_AUDIO_DEPTH depth,
ALLEGRO_CHANNEL_CONF chan_conf );
void al_destroy_voice( ALLEGRO_VOICE * voice );
bool al_attach_sample_instance_to_voice(
ALLEGRO_SAMPLE_INSTANCE * stream, ALLEGRO_VOICE * voice );
bool al_attach_audio_stream_to_voice(
ALLEGRO_AUDIO_STREAM * stream, ALLEGRO_VOICE * voice );
bool al_attach_mixer_to_voice( ALLEGRO_MIXER * mixer,
ALLEGRO_VOICE * voice );
void al_detach_voice( ALLEGRO_VOICE * voice );
unsigned int al_get_voice_frequency( const ALLEGRO_VOICE * voice );
unsigned int al_get_voice_position( const ALLEGRO_VOICE * voice );
ALLEGRO_CHANNEL_CONF al_get_voice_channels( const ALLEGRO_VOICE * voice );
ALLEGRO_AUDIO_DEPTH al_get_voice_depth( const ALLEGRO_VOICE * voice );
bool al_get_voice_playing( const ALLEGRO_VOICE * voice );
bool al_set_voice_position( ALLEGRO_VOICE * voice, unsigned int val );
bool al_set_voice_playing( ALLEGRO_VOICE * voice, bool val );
bool al_install_audio( void );
void al_uninstall_audio( void );
bool al_is_audio_installed( void );
uint32_t al_get_allegro_audio_version( void );
size_t al_get_channel_count( ALLEGRO_CHANNEL_CONF conf );
size_t al_get_audio_depth_size( ALLEGRO_AUDIO_DEPTH conf );
bool al_reserve_samples( int reserve_samples );
ALLEGRO_MIXER * al_get_default_mixer( void );
bool al_set_default_mixer( ALLEGRO_MIXER * mixer );
bool al_restore_default_mixer( void );
bool al_play_sample( ALLEGRO_SAMPLE * data,
float gain, float pan, float speed, ALLEGRO_PLAYMODE loop, ALLEGRO_SAMPLE_ID * ret_id );
void al_stop_sample( ALLEGRO_SAMPLE_ID * spl_id );
void al_stop_samples( void );
bool al_register_sample_loader( const char * ext,
ALLEGRO_SAMPLE *( * loader )( const char * filename ) );
bool al_register_sample_saver( const char * ext,
bool( * saver )( const char * filename, ALLEGRO_SAMPLE * spl ) );
bool al_register_audio_stream_loader( const char * ext,
ALLEGRO_AUDIO_STREAM *( * stream_loader )( const char * filename,
size_t buffer_count, unsigned int samples ) );
bool al_register_sample_loader_f( const char * ext,
ALLEGRO_SAMPLE *( * loader )( ALLEGRO_FILE * fp ) );
bool al_register_sample_saver_f( const char * ext,
bool( * saver )( ALLEGRO_FILE * fp, ALLEGRO_SAMPLE * spl ) );
bool al_register_audio_stream_loader_f( const char * ext,
ALLEGRO_AUDIO_STREAM *( * stream_loader )( ALLEGRO_FILE * fp,
size_t buffer_count, unsigned int samples ) );
ALLEGRO_SAMPLE * al_load_sample( const char * filename );
bool al_save_sample( const char * filename,
ALLEGRO_SAMPLE * spl );
ALLEGRO_AUDIO_STREAM * al_load_audio_stream( const char * filename,
size_t buffer_count, unsigned int samples );
ALLEGRO_SAMPLE * al_load_sample_f( ALLEGRO_FILE * fp, const char * ident );
bool al_save_sample_f( ALLEGRO_FILE * fp, const char * ident,
ALLEGRO_SAMPLE * spl );
ALLEGRO_AUDIO_STREAM * al_load_audio_stream_f( ALLEGRO_FILE * fp, const char * ident,
size_t buffer_count, unsigned int samples );


// allegro_color.h - Plik7
uint32_t al_get_allegro_color_version( void );
void al_color_hsv_to_rgb( float hue, float saturation,
float value, float * red, float * green, float * blue );
void al_color_rgb_to_hsl( float red, float green, float blue,
float * hue, float * saturation, float * lightness );
void al_color_rgb_to_hsv( float red, float green, float blue,
float * hue, float * saturation, float * value );
void al_color_hsl_to_rgb( float hue, float saturation, float lightness,
float * red, float * green, float * blue );
bool al_color_name_to_rgb( char const * name, float * r, float * g,
float * b );
const char * al_color_rgb_to_name( float r, float g, float b );
void al_color_cmyk_to_rgb( float cyan, float magenta, float yellow,
float key, float * red, float * green, float * blue );
void al_color_rgb_to_cmyk( float red, float green, float blue,
float * cyan, float * magenta, float * yellow, float * key );
void al_color_yuv_to_rgb( float y, float u, float v,
float * red, float * green, float * blue );
void al_color_rgb_to_yuv( float red, float green, float blue,
float * y, float * u, float * v );
void al_color_rgb_to_html( float red, float green, float blue,
char * string );
void al_color_html_to_rgb( char const * string,
float * red, float * green, float * blue );
ALLEGRO_COLOR al_color_yuv( float y, float u, float v );
ALLEGRO_COLOR al_color_cmyk( float c, float m, float y, float k );
ALLEGRO_COLOR al_color_hsl( float h, float s, float l );
ALLEGRO_COLOR al_color_hsv( float h, float s, float v );
ALLEGRO_COLOR al_color_name( char const * name );
ALLEGRO_COLOR al_color_html( char const * string );


// allegro_direct3d.h - Plik8
LPDIRECT3DDEVICE9 al_get_d3d_device( ALLEGRO_DISPLAY * );
LPDIRECT3DTEXTURE9 al_get_d3d_system_texture( ALLEGRO_BITMAP * );
LPDIRECT3DTEXTURE9 al_get_d3d_video_texture( ALLEGRO_BITMAP * );
bool al_have_d3d_non_pow2_texture_support( void );
bool al_have_d3d_non_square_texture_support( void );
void al_get_d3d_texture_position( ALLEGRO_BITMAP * bitmap, int * u, int * v );
bool al_is_d3d_device_lost( ALLEGRO_DISPLAY * display );


// allegro_font.h - Plik9
bool al_register_font_loader( const char * ext, ALLEGRO_FONT *( * load )( const char * filename, int size, int flags ) );
ALLEGRO_FONT * al_load_bitmap_font( const char * filename );
ALLEGRO_FONT * al_load_font( const char * filename, int size, int flags );
ALLEGRO_FONT * al_grab_font_from_bitmap( ALLEGRO_BITMAP * bmp, int n, int ranges[] );
void al_draw_ustr( const ALLEGRO_FONT * font, ALLEGRO_COLOR color, float x, float y, int flags, ALLEGRO_USTR const * ustr );
void al_draw_text( const ALLEGRO_FONT * font, ALLEGRO_COLOR color, float x, float y, int flags, char const * text );
void al_draw_justified_text( const ALLEGRO_FONT * font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, char const * text );
void al_draw_justified_ustr( const ALLEGRO_FONT * font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, ALLEGRO_USTR const * text );
void al_draw_textf( const ALLEGRO_FONT * font, ALLEGRO_COLOR color, float x, float y, int flags, char const * format,...), 6, 7;
void al_draw_justified_textf( const ALLEGRO_FONT * font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, char const * format,...), 8, 9;
int al_get_text_width( const ALLEGRO_FONT * f, const char * str );
int al_get_ustr_width( const ALLEGRO_FONT * f, const ALLEGRO_USTR * ustr );
int al_get_font_line_height( const ALLEGRO_FONT * f );
int al_get_font_ascent( const ALLEGRO_FONT * f );
int al_get_font_descent( const ALLEGRO_FONT * f );
void al_destroy_font( ALLEGRO_FONT * f );
void al_get_ustr_dimensions( const ALLEGRO_FONT * f,
ALLEGRO_USTR const * text,
int * bbx, int * bby, int * bbw, int * bbh );
void al_get_text_dimensions( const ALLEGRO_FONT * f,
char const * text,
int * bbx, int * bby, int * bbw, int * bbh );
void al_init_font_addon( void );
void al_shutdown_font_addon( void );
uint32_t al_get_allegro_font_version( void );


// allegro_image.h - Plik10
bool al_init_image_addon( void );
void al_shutdown_image_addon( void );
uint32_t al_get_allegro_image_version( void );


// allegro_iphone.h - Plik11
void al_iphone_program_has_halted( void );
void al_iphone_override_screen_scale( float scale );


// allegro_memfile.h - Plik12
ALLEGRO_FILE * al_open_memfile( void * mem, int64_t size, const char * mode );
uint32_t al_get_allegro_memfile_version( void );


// allegro_native_dialog.h - Plik13
ALLEGRO_FILECHOOSER * al_create_native_file_dialog( char const * initial_path,
char const * title, char const * patterns, int mode );
bool al_show_native_file_dialog( ALLEGRO_DISPLAY * display, ALLEGRO_FILECHOOSER * dialog );
int al_get_native_file_dialog_count( const ALLEGRO_FILECHOOSER * dialog );
const char * al_get_native_file_dialog_path( const ALLEGRO_FILECHOOSER * dialog,
size_t index );
void al_destroy_native_file_dialog( ALLEGRO_FILECHOOSER * dialog );
int al_show_native_message_box( ALLEGRO_DISPLAY * display, char const * title,
char const * heading, char const * text, char const * buttons, int flags );
ALLEGRO_TEXTLOG * al_open_native_text_log( char const * title, int flags );
void al_close_native_text_log( ALLEGRO_TEXTLOG * textlog );
void al_append_native_text_log( ALLEGRO_TEXTLOG * textlog, char const * format,...);
ALLEGRO_EVENT_SOURCE * al_get_native_text_log_event_source( ALLEGRO_TEXTLOG * textlog );
uint32_t al_get_allegro_native_dialog_version( void );


// allegro_opengl.h - Plik14
uint32_t al_get_opengl_version( void );
bool al_have_opengl_extension( const char * extension );
void * al_get_opengl_proc_address( const char * name );
ALLEGRO_OGL_EXT_LIST * al_get_opengl_extension_list( void );
GLuint al_get_opengl_texture( ALLEGRO_BITMAP * bitmap );
void al_remove_opengl_fbo( ALLEGRO_BITMAP * bitmap );
GLuint al_get_opengl_fbo( ALLEGRO_BITMAP * bitmap );
void al_get_opengl_texture_size( ALLEGRO_BITMAP * bitmap,
int * w, int * h );
void al_get_opengl_texture_position( ALLEGRO_BITMAP * bitmap,
int * u, int * v );
void al_set_current_opengl_context( ALLEGRO_DISPLAY * display );
int al_get_opengl_variant( void );


// allegro_physfs.h - Plik15
void al_set_physfs_file_interface( void );
uint32_t al_get_allegro_physfs_version( void );


// allegro_primitives.h - Plik16
uint32_t al_get_allegro_primitives_version( void );
bool al_init_primitives_addon( void );
void al_shutdown_primitives_addon( void );
int al_draw_prim( const void * vtxs, const ALLEGRO_VERTEX_DECL * decl, ALLEGRO_BITMAP * texture, int start, int end, int type );
int al_draw_indexed_prim( const void * vtxs, const ALLEGRO_VERTEX_DECL * decl, ALLEGRO_BITMAP * texture, const int * indices, int num_vtx, int type );
ALLEGRO_VERTEX_DECL * al_create_vertex_decl( const ALLEGRO_VERTEX_ELEMENT * elements, int stride );
void al_destroy_vertex_decl( ALLEGRO_VERTEX_DECL * decl );
void al_draw_soft_triangle( ALLEGRO_VERTEX * v1, ALLEGRO_VERTEX * v2, ALLEGRO_VERTEX * v3, uintptr_t state,
void( * init )( uintptr_t, ALLEGRO_VERTEX *, ALLEGRO_VERTEX *, ALLEGRO_VERTEX * ),
void( * first )( uintptr_t, int, int, int, int ),
void( * step )( uintptr_t, int ),
void( * draw )( uintptr_t, int, int, int ) );
void al_draw_soft_line( ALLEGRO_VERTEX * v1, ALLEGRO_VERTEX * v2, uintptr_t state,
void( * first )( uintptr_t, int, int, ALLEGRO_VERTEX *, ALLEGRO_VERTEX * ),
void( * step )( uintptr_t, int ),
void( * draw )( uintptr_t, int, int ) );
void al_draw_line( float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness );
void al_draw_triangle( float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color, float thickness );
void al_draw_rectangle( float x1, float y1, float x2, float y2, ALLEGRO_COLOR color, float thickness );
void al_draw_rounded_rectangle( float x1, float y1, float x2, float y2, float rx, float ry, ALLEGRO_COLOR color, float thickness );
void al_calculate_arc( float * dest, int stride, float cx, float cy, float rx, float ry, float start_theta, float delta_theta, float thickness, int num_segments );
void al_draw_circle( float cx, float cy, float r, ALLEGRO_COLOR color, float thickness );
void al_draw_ellipse( float cx, float cy, float rx, float ry, ALLEGRO_COLOR color, float thickness );
void al_draw_arc( float cx, float cy, float r, float start_theta, float delta_theta, ALLEGRO_COLOR color, float thickness );
void al_draw_elliptical_arc( float cx, float cy, float rx, float ry, float start_theta, float delta_theta, ALLEGRO_COLOR color, float thickness );
void al_draw_pieslice( float cx, float cy, float r, float start_theta, float delta_theta, ALLEGRO_COLOR color, float thickness );
void al_calculate_spline( float * dest, int stride, float points[ 8 ], float thickness, int num_segments );
void al_draw_spline( float points[ 8 ], ALLEGRO_COLOR color, float thickness );
void al_calculate_ribbon( float * dest, int dest_stride, const float * points, int points_stride, float thickness, int num_segments );
void al_draw_ribbon( const float * points, int points_stride, ALLEGRO_COLOR color, float thickness, int num_segments );
void al_draw_filled_triangle( float x1, float y1, float x2, float y2, float x3, float y3, ALLEGRO_COLOR color );
void al_draw_filled_rectangle( float x1, float y1, float x2, float y2, ALLEGRO_COLOR color );
void al_draw_filled_ellipse( float cx, float cy, float rx, float ry, ALLEGRO_COLOR color );
void al_draw_filled_circle( float cx, float cy, float r, ALLEGRO_COLOR color );
void al_draw_filled_pieslice( float cx, float cy, float r, float start_theta, float delta_theta, ALLEGRO_COLOR color );
void al_draw_filled_rounded_rectangle( float x1, float y1, float x2, float y2, float rx, float ry, ALLEGRO_COLOR color );


// allegro_ttf.h - Plik17
ALLEGRO_FONT * al_load_ttf_font( char const * filename, int size, int flags );
ALLEGRO_FONT * al_load_ttf_font_f( ALLEGRO_FILE * file, char const * filename, int size, int flags );
ALLEGRO_FONT * al_load_ttf_font_stretch( char const * filename, int w, int h, int flags );
ALLEGRO_FONT * al_load_ttf_font_stretch_f( ALLEGRO_FILE * file, char const * filename, int w, int h, int flags );
bool al_init_ttf_addon( void );
void al_shutdown_ttf_addon( void );
uint32_t al_get_allegro_ttf_version( void );


// allegro_windows.h - Plik18
HWND al_get_win_window_handle( ALLEGRO_DISPLAY * );


// altime.h - Plik19
double al_get_time( void );
void al_rest( double seconds );
void al_init_timeout( ALLEGRO_TIMEOUT * timeout, double seconds );


// base.h - Plik20
uint32_t al_get_allegro_version( void );
int al_run_main( int argc, char ** argv, int( * )( int, char ** ) );


// bitmap.h - Plik21
void al_set_new_bitmap_format( int format );
void al_set_new_bitmap_flags( int flags );
int al_get_new_bitmap_format( void );
int al_get_new_bitmap_flags( void );
void al_add_new_bitmap_flag( int flag );
int al_get_bitmap_width( ALLEGRO_BITMAP * bitmap );
int al_get_bitmap_height( ALLEGRO_BITMAP * bitmap );
int al_get_bitmap_format( ALLEGRO_BITMAP * bitmap );
int al_get_bitmap_flags( ALLEGRO_BITMAP * bitmap );
ALLEGRO_BITMAP * al_create_bitmap( int w, int h );
void al_destroy_bitmap( ALLEGRO_BITMAP * bitmap );
void al_draw_bitmap( ALLEGRO_BITMAP * bitmap, float dx, float dy, int flags );
void al_draw_bitmap_region( ALLEGRO_BITMAP * bitmap, float sx, float sy, float sw, float sh, float dx, float dy, int flags );
void al_draw_scaled_bitmap( ALLEGRO_BITMAP * bitmap, float sx, float sy, float sw, float sh, float dx, float dy, float dw, float dh, int flags );
void al_draw_rotated_bitmap( ALLEGRO_BITMAP * bitmap, float cx, float cy, float dx, float dy, float angle, int flags );
void al_draw_scaled_rotated_bitmap( ALLEGRO_BITMAP * bitmap, float cx, float cy, float dx, float dy, float xscale, float yscale, float angle, int flags );
void al_draw_tinted_bitmap( ALLEGRO_BITMAP * bitmap, ALLEGRO_COLOR tint, float dx, float dy, int flags );
void al_draw_tinted_bitmap_region( ALLEGRO_BITMAP * bitmap, ALLEGRO_COLOR tint, float sx, float sy, float sw, float sh, float dx, float dy, int flags );
void al_draw_tinted_scaled_bitmap( ALLEGRO_BITMAP * bitmap, ALLEGRO_COLOR tint, float sx, float sy, float sw, float sh, float dx, float dy, float dw, float dh, int flags );
void al_draw_tinted_rotated_bitmap( ALLEGRO_BITMAP * bitmap, ALLEGRO_COLOR tint, float cx, float cy, float dx, float dy, float angle, int flags );
void al_draw_tinted_scaled_rotated_bitmap( ALLEGRO_BITMAP * bitmap, ALLEGRO_COLOR tint, float cx, float cy, float dx, float dy, float xscale, float yscale, float angle, int flags );
void al_draw_tinted_scaled_rotated_bitmap_region(
ALLEGRO_BITMAP * bitmap,
float sx, float sy, float sw, float sh,
ALLEGRO_COLOR tint,
float cx, float cy, float dx, float dy, float xscale, float yscale,
float angle, int flags );
ALLEGRO_LOCKED_REGION * al_lock_bitmap( ALLEGRO_BITMAP * bitmap, int format, int flags );
ALLEGRO_LOCKED_REGION * al_lock_bitmap_region( ALLEGRO_BITMAP * bitmap, int x, int y, int width, int height, int format, int flags );
void al_unlock_bitmap( ALLEGRO_BITMAP * bitmap );
void al_put_pixel( int x, int y, ALLEGRO_COLOR color );
void al_put_blended_pixel( int x, int y, ALLEGRO_COLOR color );
ALLEGRO_COLOR al_get_pixel( ALLEGRO_BITMAP * bitmap, int x, int y );
int al_get_pixel_size( int format );
ALLEGRO_COLOR al_map_rgb( unsigned char r, unsigned char g, unsigned char b );
ALLEGRO_COLOR al_map_rgba( unsigned char r, unsigned char g, unsigned char b, unsigned char a );
ALLEGRO_COLOR al_map_rgb_f( float r, float g, float b );
ALLEGRO_COLOR al_map_rgba_f( float r, float g, float b, float a );
void al_unmap_rgb( ALLEGRO_COLOR color, unsigned char * r, unsigned char * g, unsigned char * b );
void al_unmap_rgba( ALLEGRO_COLOR color, unsigned char * r, unsigned char * g, unsigned char * b, unsigned char * a );
void al_unmap_rgb_f( ALLEGRO_COLOR color, float * r, float * g, float * b );
void al_unmap_rgba_f( ALLEGRO_COLOR color, float * r, float * g, float * b, float * a );
int al_get_pixel_format_bits( int format );
void al_convert_mask_to_alpha( ALLEGRO_BITMAP * bitmap, ALLEGRO_COLOR mask_color );
void al_set_clipping_rectangle( int x, int y, int width, int height );
void al_reset_clipping_rectangle( void );
void al_get_clipping_rectangle( int * x, int * y, int * w, int * h );
ALLEGRO_BITMAP * al_create_sub_bitmap( ALLEGRO_BITMAP * parent, int x, int y, int w, int h );
bool al_is_sub_bitmap( ALLEGRO_BITMAP * bitmap );
ALLEGRO_BITMAP * al_get_parent_bitmap( ALLEGRO_BITMAP * bitmap );
ALLEGRO_BITMAP * al_clone_bitmap( ALLEGRO_BITMAP * bitmap );
bool al_is_bitmap_locked( ALLEGRO_BITMAP * bitmap );
void al_set_blender( int op, int source, int dest );
void al_get_blender( int * op, int * source, int * dest );
void al_set_separate_blender( int op, int source, int dest,
int alpha_op, int alpha_source, int alpha_dest );
void al_get_separate_blender( int * op, int * source, int * dest,
int * alpha_op, int * alpha_src, int * alpha_dest );
void _al_put_pixel( ALLEGRO_BITMAP * bitmap, int x, int y, ALLEGRO_COLOR color );


// bitmap_io.h - Plik22
bool al_register_bitmap_loader( const char * ext, ALLEGRO_IIO_LOADER_FUNCTION loader );
bool al_register_bitmap_saver( const char * ext, ALLEGRO_IIO_SAVER_FUNCTION saver );
bool al_register_bitmap_loader_f( const char * ext, ALLEGRO_IIO_FS_LOADER_FUNCTION fs_loader );
bool al_register_bitmap_saver_f( const char * ext, ALLEGRO_IIO_FS_SAVER_FUNCTION fs_saver );
ALLEGRO_BITMAP * al_load_bitmap( const char * filename );
ALLEGRO_BITMAP * al_load_bitmap_f( ALLEGRO_FILE * fp, const char * ident );
bool al_save_bitmap( const char * filename, ALLEGRO_BITMAP * bitmap );
bool al_save_bitmap_f( ALLEGRO_FILE * fp, const char * ident, ALLEGRO_BITMAP * bitmap );


// color.h - Plik23
// ***nie znaleziono żadnej funkcji***

// config.h - Plik24
ALLEGRO_CONFIG * al_create_config( void );
void al_add_config_section( ALLEGRO_CONFIG * config, const char * name );
void al_set_config_value( ALLEGRO_CONFIG * config, const char * section, const char * key, const char * value );
void al_add_config_comment( ALLEGRO_CONFIG * config, const char * section, const char * comment );
const char * al_get_config_value( const ALLEGRO_CONFIG * config, const char * section, const char * key );
ALLEGRO_CONFIG * al_load_config_file( const char * filename );
ALLEGRO_CONFIG * al_load_config_file_f( ALLEGRO_FILE * filename );
bool al_save_config_file( const char * filename, const ALLEGRO_CONFIG * config );
bool al_save_config_file_f( ALLEGRO_FILE * file, const ALLEGRO_CONFIG * config );
void al_merge_config_into( ALLEGRO_CONFIG * master, const ALLEGRO_CONFIG * add );
ALLEGRO_CONFIG * al_merge_config( const ALLEGRO_CONFIG * cfg1, const ALLEGRO_CONFIG * cfg2 );
void al_destroy_config( ALLEGRO_CONFIG * config );
char const * al_get_first_config_section( ALLEGRO_CONFIG const * config, ALLEGRO_CONFIG_SECTION ** iterator );
char const * al_get_next_config_section( ALLEGRO_CONFIG_SECTION ** iterator );
char const * al_get_first_config_entry( ALLEGRO_CONFIG const * config, char const * section,
ALLEGRO_CONFIG_ENTRY ** iterator );
char const * al_get_next_config_entry( ALLEGRO_CONFIG_ENTRY ** iterator );


// debug.h - Plik25
bool _al_trace_prefix( char const * channel, int level,
char const * file, int line, char const * function );
void _al_trace_suffix( const char * msg,...), 1, 2;
void _al_user_assert_handler( char const * expr, char const * file,
int line, char const * func );
void al_register_assert_handler( void( * handler )( char const * expr,
char const * file, int line, char const * func ) );


// display.h - Plik26
void al_set_new_display_refresh_rate( int refresh_rate );
void al_set_new_display_flags( int flags );
int al_get_new_display_refresh_rate( void );
int al_get_new_display_flags( void );
int al_get_display_width( ALLEGRO_DISPLAY * display );
int al_get_display_height( ALLEGRO_DISPLAY * display );
int al_get_display_format( ALLEGRO_DISPLAY * display );
int al_get_display_refresh_rate( ALLEGRO_DISPLAY * display );
int al_get_display_flags( ALLEGRO_DISPLAY * display );
bool al_set_display_flag( ALLEGRO_DISPLAY * display, int flag, bool onoff );
bool al_toggle_display_flag( ALLEGRO_DISPLAY * display, int flag, bool onoff );
ALLEGRO_DISPLAY * al_create_display( int w, int h );
void al_destroy_display( ALLEGRO_DISPLAY * display );
ALLEGRO_DISPLAY * al_get_current_display( void );
void al_set_target_bitmap( ALLEGRO_BITMAP * bitmap );
void al_set_target_backbuffer( ALLEGRO_DISPLAY * display );
ALLEGRO_BITMAP * al_get_backbuffer( ALLEGRO_DISPLAY * display );
ALLEGRO_BITMAP * al_get_target_bitmap( void );
bool al_acknowledge_resize( ALLEGRO_DISPLAY * display );
bool al_resize_display( ALLEGRO_DISPLAY * display, int width, int height );
void al_flip_display( void );
void al_update_display_region( int x, int y, int width, int height );
bool al_is_compatible_bitmap( ALLEGRO_BITMAP * bitmap );
int al_get_num_display_modes( void );
ALLEGRO_DISPLAY_MODE * al_get_display_mode( int index,
ALLEGRO_DISPLAY_MODE * mode );
bool al_wait_for_vsync( void );
ALLEGRO_EVENT_SOURCE * al_get_display_event_source( ALLEGRO_DISPLAY * display );
void al_clear_to_color( ALLEGRO_COLOR color );
void al_draw_pixel( float x, float y, ALLEGRO_COLOR color );
void al_set_display_icon( ALLEGRO_DISPLAY * display, ALLEGRO_BITMAP * icon );
int al_get_num_video_adapters( void );
bool al_get_monitor_info( int adapter, ALLEGRO_MONITOR_INFO * info );
int al_get_new_display_adapter( void );
void al_set_new_display_adapter( int adapter );
void al_set_new_window_position( int x, int y );
void al_get_new_window_position( int * x, int * y );
void al_set_window_position( ALLEGRO_DISPLAY * display, int x, int y );
void al_get_window_position( ALLEGRO_DISPLAY * display, int * x, int * y );
void al_set_window_title( ALLEGRO_DISPLAY * display, const char * title );
void al_set_new_display_option( int option, int value, int importance );
int al_get_new_display_option( int option, int * importance );
void al_reset_new_display_options( void );
int al_get_display_option( ALLEGRO_DISPLAY * display, int option );
void al_hold_bitmap_drawing( bool hold );
bool al_is_bitmap_drawing_held( void );


// error.h - Plik27
int al_get_errno( void );
void al_set_errno( int errnum );


// events.h - Plik28
void al_init_user_event_source( ALLEGRO_EVENT_SOURCE * );
void al_destroy_user_event_source( ALLEGRO_EVENT_SOURCE * );
bool al_emit_user_event( ALLEGRO_EVENT_SOURCE *, ALLEGRO_EVENT *,
void( * dtor )( ALLEGRO_USER_EVENT * ) );
void al_unref_user_event( ALLEGRO_USER_EVENT * );
void al_set_event_source_data( ALLEGRO_EVENT_SOURCE *, intptr_t data );
intptr_t al_get_event_source_data( const ALLEGRO_EVENT_SOURCE * );
ALLEGRO_EVENT_QUEUE * al_create_event_queue( void );
void al_destroy_event_queue( ALLEGRO_EVENT_QUEUE * );
void al_register_event_source( ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT_SOURCE * );
void al_unregister_event_source( ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT_SOURCE * );
bool al_is_event_queue_empty( ALLEGRO_EVENT_QUEUE * );
bool al_get_next_event( ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT * ret_event );
bool al_peek_next_event( ALLEGRO_EVENT_QUEUE *, ALLEGRO_EVENT * ret_event );
bool al_drop_next_event( ALLEGRO_EVENT_QUEUE * );
void al_flush_event_queue( ALLEGRO_EVENT_QUEUE * );
void al_wait_for_event( ALLEGRO_EVENT_QUEUE *,
ALLEGRO_EVENT * ret_event );
bool al_wait_for_event_timed( ALLEGRO_EVENT_QUEUE *,
ALLEGRO_EVENT * ret_event,
float secs );
bool al_wait_for_event_until( ALLEGRO_EVENT_QUEUE * queue,
ALLEGRO_EVENT * ret_event,
ALLEGRO_TIMEOUT * timeout );


// file.h - Plik29
ALLEGRO_FILE * al_fopen( const char * path, const char * mode );
ALLEGRO_FILE * al_fopen_interface( const ALLEGRO_FILE_INTERFACE * vt, const char * path, const char * mode );
ALLEGRO_FILE * al_create_file_handle( const ALLEGRO_FILE_INTERFACE * vt, void * userdata );
void al_fclose( ALLEGRO_FILE * f );
size_t al_fread( ALLEGRO_FILE * f, void * ptr, size_t size );
size_t al_fwrite( ALLEGRO_FILE * f, const void * ptr, size_t size );
bool al_fflush( ALLEGRO_FILE * f );
int64_t al_ftell( ALLEGRO_FILE * f );
bool al_fseek( ALLEGRO_FILE * f, int64_t offset, int whence );
bool al_feof( ALLEGRO_FILE * f );
bool al_ferror( ALLEGRO_FILE * f );
void al_fclearerr( ALLEGRO_FILE * f );
int al_fungetc( ALLEGRO_FILE * f, int c );
int64_t al_fsize( ALLEGRO_FILE * f );
int al_fgetc( ALLEGRO_FILE * f );
int al_fputc( ALLEGRO_FILE * f, int c );
int16_t al_fread16le( ALLEGRO_FILE * f );
int16_t al_fread16be( ALLEGRO_FILE * f );
size_t al_fwrite16le( ALLEGRO_FILE * f, int16_t w );
size_t al_fwrite16be( ALLEGRO_FILE * f, int16_t w );
int32_t al_fread32le( ALLEGRO_FILE * f );
int32_t al_fread32be( ALLEGRO_FILE * f );
size_t al_fwrite32le( ALLEGRO_FILE * f, int32_t l );
size_t al_fwrite32be( ALLEGRO_FILE * f, int32_t l );
char * al_fgets( ALLEGRO_FILE * f, char * const p, size_t max );
ALLEGRO_USTR * al_fget_ustr( ALLEGRO_FILE * f );
int al_fputs( ALLEGRO_FILE * f, const char * p );
ALLEGRO_FILE * al_fopen_fd( int fd, const char * mode );
ALLEGRO_FILE * al_make_temp_file( const char * tmpl,
ALLEGRO_PATH ** ret_path );
ALLEGRO_FILE * al_fopen_slice( ALLEGRO_FILE * fp,
size_t initial_size, const char * mode );
const ALLEGRO_FILE_INTERFACE * al_get_new_file_interface( void );
void al_set_new_file_interface( const ALLEGRO_FILE_INTERFACE *
file_interface );
void al_set_standard_file_interface( void );
void * al_get_file_userdata( ALLEGRO_FILE * f );


// fixed.h - Plik30
// ***nie znaleziono żadnej funkcji***

// fmaths.h - Plik31
al_fixed al_fixsqrt( al_fixed x );
al_fixed al_fixhypot( al_fixed x, al_fixed y );
al_fixed al_fixatan( al_fixed x );
al_fixed al_fixatan2( al_fixed y, al_fixed x );


// fshook.h - Plik32
ALLEGRO_FS_ENTRY * al_create_fs_entry( const char * path );
void al_destroy_fs_entry( ALLEGRO_FS_ENTRY * e );
const char * al_get_fs_entry_name( ALLEGRO_FS_ENTRY * e );
bool al_update_fs_entry( ALLEGRO_FS_ENTRY * e );
uint32_t al_get_fs_entry_mode( ALLEGRO_FS_ENTRY * e );
time_t al_get_fs_entry_atime( ALLEGRO_FS_ENTRY * e );
time_t al_get_fs_entry_mtime( ALLEGRO_FS_ENTRY * e );
time_t al_get_fs_entry_ctime( ALLEGRO_FS_ENTRY * e );
off_t al_get_fs_entry_size( ALLEGRO_FS_ENTRY * e );
bool al_fs_entry_exists( ALLEGRO_FS_ENTRY * e );
bool al_remove_fs_entry( ALLEGRO_FS_ENTRY * e );
bool al_open_directory( ALLEGRO_FS_ENTRY * e );
ALLEGRO_FS_ENTRY * al_read_directory( ALLEGRO_FS_ENTRY * e );
bool al_close_directory( ALLEGRO_FS_ENTRY * e );
bool al_filename_exists( const char * path );
bool al_remove_filename( const char * path );
char * al_get_current_directory( void );
bool al_change_directory( const char * path );
bool al_make_directory( const char * path );
ALLEGRO_FILE * al_open_fs_entry( ALLEGRO_FS_ENTRY * e,
const char * mode );
const ALLEGRO_FS_INTERFACE * al_get_fs_interface( void );
void al_set_fs_interface( const ALLEGRO_FS_INTERFACE * vtable );
void al_set_standard_fs_interface( void );


// joystick.h - Plik33
bool al_install_joystick( void );
void al_uninstall_joystick( void );
bool al_is_joystick_installed( void );
bool al_reconfigure_joysticks( void );
int al_get_num_joysticks( void );
ALLEGRO_JOYSTICK * al_get_joystick( int joyn );
void al_release_joystick( ALLEGRO_JOYSTICK * );
bool al_get_joystick_active( ALLEGRO_JOYSTICK * );
const char * al_get_joystick_name( ALLEGRO_JOYSTICK * );
int al_get_joystick_num_sticks( ALLEGRO_JOYSTICK * );
int al_get_joystick_stick_flags( ALLEGRO_JOYSTICK *, int stick ); /* junk? */
const char * al_get_joystick_stick_name( ALLEGRO_JOYSTICK *, int stick );
int al_get_joystick_num_axes( ALLEGRO_JOYSTICK *, int stick );
const char * al_get_joystick_axis_name( ALLEGRO_JOYSTICK *, int stick, int axis );
int al_get_joystick_num_buttons( ALLEGRO_JOYSTICK * );
const char * al_get_joystick_button_name( ALLEGRO_JOYSTICK *, int buttonn );
void al_get_joystick_state( ALLEGRO_JOYSTICK *, ALLEGRO_JOYSTICK_STATE * ret_state );
ALLEGRO_EVENT_SOURCE * al_get_joystick_event_source( void );


// keyboard.h - Plik34
bool al_is_keyboard_installed( void );
bool al_install_keyboard( void );
void al_uninstall_keyboard( void );
bool al_set_keyboard_leds( int leds );
const char * al_keycode_to_name( int keycode );
void al_get_keyboard_state( ALLEGRO_KEYBOARD_STATE * ret_state );
bool al_key_down( const ALLEGRO_KEYBOARD_STATE *, int keycode );
ALLEGRO_EVENT_SOURCE * al_get_keyboard_event_source( void );


// keycodes.h - Plik35
// ***nie znaleziono żadnej funkcji***

// memory.h - Plik36
void al_set_memory_interface( ALLEGRO_MEMORY_INTERFACE * iface );
void * al_malloc_with_context( size_t n,
int line, const char * file, const char * func );
void al_free_with_context( void * ptr,
int line, const char * file, const char * func );
void * al_realloc_with_context( void * ptr, size_t n,
int line, const char * file, const char * func );
void * al_calloc_with_context( size_t count, size_t n,
int line, const char * file, const char * func );


// mouse.h - Plik37
bool al_is_mouse_installed( void );
bool al_install_mouse( void );
void al_uninstall_mouse( void );
unsigned int al_get_mouse_num_buttons( void );
unsigned int al_get_mouse_num_axes( void );
bool al_set_mouse_xy( struct ALLEGRO_DISPLAY * display, int x, int y );
bool al_set_mouse_z( int z );
bool al_set_mouse_w( int w );
bool al_set_mouse_axis( int axis, int value );
void al_get_mouse_state( ALLEGRO_MOUSE_STATE * ret_state );
bool al_mouse_button_down( const ALLEGRO_MOUSE_STATE * state, int button );
int al_get_mouse_state_axis( const ALLEGRO_MOUSE_STATE * state, int axis );
ALLEGRO_EVENT_SOURCE * al_get_mouse_event_source( void );
ALLEGRO_MOUSE_CURSOR * al_create_mouse_cursor(
struct ALLEGRO_BITMAP * sprite, int xfocus, int yfocus );
void al_destroy_mouse_cursor( ALLEGRO_MOUSE_CURSOR * );
bool al_set_mouse_cursor( struct ALLEGRO_DISPLAY * display,
ALLEGRO_MOUSE_CURSOR * cursor );
bool al_set_system_mouse_cursor( struct ALLEGRO_DISPLAY * display,
ALLEGRO_SYSTEM_MOUSE_CURSOR cursor_id );
bool al_show_mouse_cursor( struct ALLEGRO_DISPLAY * display );
bool al_hide_mouse_cursor( struct ALLEGRO_DISPLAY * display );
bool al_get_mouse_cursor_position( int * ret_x, int * ret_y );
bool al_grab_mouse( struct ALLEGRO_DISPLAY * display );
bool al_ungrab_mouse( void );


// path.h - Plik38
ALLEGRO_PATH * al_create_path( const char * str );
ALLEGRO_PATH * al_create_path_for_directory( const char * str );
ALLEGRO_PATH * al_clone_path( const ALLEGRO_PATH * path );
int al_get_path_num_components( const ALLEGRO_PATH * path );
const char * al_get_path_component( const ALLEGRO_PATH * path, int i );
void al_replace_path_component( ALLEGRO_PATH * path, int i, const char * s );
void al_remove_path_component( ALLEGRO_PATH * path, int i );
void al_insert_path_component( ALLEGRO_PATH * path, int i, const char * s );
const char * al_get_path_tail( const ALLEGRO_PATH * path );
void al_drop_path_tail( ALLEGRO_PATH * path );
void al_append_path_component( ALLEGRO_PATH * path, const char * s );
bool al_join_paths( ALLEGRO_PATH * path, const ALLEGRO_PATH * tail );
bool al_rebase_path( const ALLEGRO_PATH * head, ALLEGRO_PATH * tail );
const char * al_path_cstr( const ALLEGRO_PATH * path, char delim );
void al_destroy_path( ALLEGRO_PATH * path );
void al_set_path_drive( ALLEGRO_PATH * path, const char * drive );
const char * al_get_path_drive( const ALLEGRO_PATH * path );
void al_set_path_filename( ALLEGRO_PATH * path, const char * filename );
const char * al_get_path_filename( const ALLEGRO_PATH * path );
const char * al_get_path_extension( const ALLEGRO_PATH * path );
bool al_set_path_extension( ALLEGRO_PATH * path, char const * extension );
const char * al_get_path_basename( const ALLEGRO_PATH * path );
bool al_make_path_canonical( ALLEGRO_PATH * path );


// system.h - Plik39
bool al_install_system( int version, int( * atexit_ptr )( void( * )( void ) ) );
void al_uninstall_system( void );
bool al_is_system_installed( void );
ALLEGRO_SYSTEM * al_get_system_driver( void );
ALLEGRO_CONFIG * al_get_system_config( void );
ALLEGRO_PATH * al_get_standard_path( int id );
void al_set_exe_name( char const * path );
void al_set_org_name( const char * org_name );
void al_set_app_name( const char * app_name );
const char * al_get_org_name( void );
const char * al_get_app_name( void );
bool al_inhibit_screensaver( bool inhibit );


// threads.h - Plik40
ALLEGRO_THREAD * al_create_thread
( void *( * proc )( ALLEGRO_THREAD * thread, void * arg ), void * arg );
void al_start_thread( ALLEGRO_THREAD * outer );
void al_join_thread( ALLEGRO_THREAD * outer, void ** ret_value );
void al_set_thread_should_stop( ALLEGRO_THREAD * outer );
bool al_get_thread_should_stop( ALLEGRO_THREAD * outer );
void al_destroy_thread( ALLEGRO_THREAD * thread );
void al_run_detached_thread( void *( * proc )( void * arg ), void * arg );
ALLEGRO_MUTEX * al_create_mutex( void );
ALLEGRO_MUTEX * al_create_mutex_recursive( void );
void al_lock_mutex( ALLEGRO_MUTEX * mutex );
void al_unlock_mutex( ALLEGRO_MUTEX * mutex );
void al_destroy_mutex( ALLEGRO_MUTEX * mutex );
ALLEGRO_COND * al_create_cond( void );
void al_destroy_cond( ALLEGRO_COND * cond );
void al_wait_cond( ALLEGRO_COND * cond, ALLEGRO_MUTEX * mutex );
int al_wait_cond_until( ALLEGRO_COND * cond, ALLEGRO_MUTEX * mutex,
const ALLEGRO_TIMEOUT * timeout );
void al_broadcast_cond( ALLEGRO_COND * cond );
void al_signal_cond( ALLEGRO_COND * cond );


// timer.h - Plik41
ALLEGRO_TIMER * al_create_timer( double speed_secs );
void al_destroy_timer( ALLEGRO_TIMER * timer );
void al_start_timer( ALLEGRO_TIMER * timer );
void al_stop_timer( ALLEGRO_TIMER * timer );
bool al_get_timer_started( const ALLEGRO_TIMER * timer );
double al_get_timer_speed( const ALLEGRO_TIMER * timer );
void al_set_timer_speed( ALLEGRO_TIMER * timer, double speed_secs );
int64_t al_get_timer_count( const ALLEGRO_TIMER * timer );
void al_set_timer_count( ALLEGRO_TIMER * timer, int64_t count );
void al_add_timer_count( ALLEGRO_TIMER * timer, int64_t diff );
ALLEGRO_EVENT_SOURCE * al_get_timer_event_source( ALLEGRO_TIMER * timer );


// tls.h - Plik42
void al_store_state( ALLEGRO_STATE * state, int flags );
void al_restore_state( ALLEGRO_STATE const * state );


// transformations.h - Plik43
void al_use_transform( const ALLEGRO_TRANSFORM * trans );
void al_copy_transform( ALLEGRO_TRANSFORM * dest, const ALLEGRO_TRANSFORM * src );
void al_identity_transform( ALLEGRO_TRANSFORM * trans );
void al_build_transform( ALLEGRO_TRANSFORM * trans, float x, float y, float sx, float sy, float theta );
void al_translate_transform( ALLEGRO_TRANSFORM * trans, float x, float y );
void al_rotate_transform( ALLEGRO_TRANSFORM * trans, float theta );
void al_scale_transform( ALLEGRO_TRANSFORM * trans, float sx, float sy );
void al_transform_coordinates( const ALLEGRO_TRANSFORM * trans, float * x, float * y );
void al_compose_transform( ALLEGRO_TRANSFORM * trans, const ALLEGRO_TRANSFORM * other );
const ALLEGRO_TRANSFORM * al_get_current_transform( void );
void al_invert_transform( ALLEGRO_TRANSFORM * trans );
int al_check_inverse( const ALLEGRO_TRANSFORM * trans, float tol );


// utf8.h - Plik44
ALLEGRO_USTR * al_ustr_new( const char * s );
ALLEGRO_USTR * al_ustr_new_from_buffer( const char * s, size_t size );
ALLEGRO_USTR * al_ustr_newf( const char * fmt,...), 1, 2;
void al_ustr_free( ALLEGRO_USTR * us );
const char * al_cstr( const ALLEGRO_USTR * us );
void al_ustr_to_buffer( const ALLEGRO_USTR * us, char * buffer, int size );
char * al_cstr_dup( const ALLEGRO_USTR * us );
ALLEGRO_USTR * al_ustr_dup( const ALLEGRO_USTR * us );
ALLEGRO_USTR * al_ustr_dup_substr( const ALLEGRO_USTR * us,
int start_pos, int end_pos );
const ALLEGRO_USTR * al_ustr_empty_string( void );
const ALLEGRO_USTR * al_ref_cstr( ALLEGRO_USTR_INFO * info, const char * s );
const ALLEGRO_USTR * al_ref_buffer( ALLEGRO_USTR_INFO * info, const char * s,
size_t size );
const ALLEGRO_USTR * al_ref_ustr( ALLEGRO_USTR_INFO * info,
const ALLEGRO_USTR * us, int start_pos, int end_pos );
size_t al_ustr_size( const ALLEGRO_USTR * us );
size_t al_ustr_length( const ALLEGRO_USTR * us );
int al_ustr_offset( const ALLEGRO_USTR * us, int index );
bool al_ustr_next( const ALLEGRO_USTR * us, int * pos );
bool al_ustr_prev( const ALLEGRO_USTR * us, int * pos );
int32_t al_ustr_get( const ALLEGRO_USTR * us, int pos );
int32_t al_ustr_get_next( const ALLEGRO_USTR * us, int * pos );
int32_t al_ustr_prev_get( const ALLEGRO_USTR * us, int * pos );
bool al_ustr_insert( ALLEGRO_USTR * us1, int pos,
const ALLEGRO_USTR * us2 );
bool al_ustr_insert_cstr( ALLEGRO_USTR * us, int pos,
const char * us2 );
size_t al_ustr_insert_chr( ALLEGRO_USTR * us, int pos, int32_t c );
bool al_ustr_append( ALLEGRO_USTR * us1, const ALLEGRO_USTR * us2 );
bool al_ustr_append_cstr( ALLEGRO_USTR * us, const char * s );
size_t al_ustr_append_chr( ALLEGRO_USTR * us, int32_t c );
bool al_ustr_appendf( ALLEGRO_USTR * us, const char * fmt,...),
2, 3;
bool al_ustr_vappendf( ALLEGRO_USTR * us, const char * fmt,
va_list ap );
bool al_ustr_remove_chr( ALLEGRO_USTR * us, int pos );
bool al_ustr_remove_range( ALLEGRO_USTR * us, int start_pos,
int end_pos );
bool al_ustr_truncate( ALLEGRO_USTR * us, int start_pos );
bool al_ustr_ltrim_ws( ALLEGRO_USTR * us );
bool al_ustr_rtrim_ws( ALLEGRO_USTR * us );
bool al_ustr_trim_ws( ALLEGRO_USTR * us );
bool al_ustr_assign( ALLEGRO_USTR * us1, const ALLEGRO_USTR * us2 );
bool al_ustr_assign_substr( ALLEGRO_USTR * us1, const ALLEGRO_USTR * us2,
int start_pos, int end_pos );
bool al_ustr_assign_cstr( ALLEGRO_USTR * us1, const char * s );
size_t al_ustr_set_chr( ALLEGRO_USTR * us, int pos, int32_t c );
bool al_ustr_replace_range( ALLEGRO_USTR * us1, int start_pos1,
int end_pos1, const ALLEGRO_USTR * us2 );
int al_ustr_find_chr( const ALLEGRO_USTR * us, int start_pos,
int32_t c );
int al_ustr_rfind_chr( const ALLEGRO_USTR * us, int start_pos,
int32_t c );
int al_ustr_find_set( const ALLEGRO_USTR * us, int start_pos,
const ALLEGRO_USTR * accept );
int al_ustr_find_set_cstr( const ALLEGRO_USTR * us, int start_pos,
const char * accept );
int al_ustr_find_cset( const ALLEGRO_USTR * us, int start_pos,
const ALLEGRO_USTR * reject );
int al_ustr_find_cset_cstr( const ALLEGRO_USTR * us, int start_pos,
const char * reject );
int al_ustr_find_str( const ALLEGRO_USTR * haystack, int start_pos,
const ALLEGRO_USTR * needle );
int al_ustr_find_cstr( const ALLEGRO_USTR * haystack, int start_pos,
const char * needle );
int al_ustr_rfind_str( const ALLEGRO_USTR * haystack, int start_pos,
const ALLEGRO_USTR * needle );
int al_ustr_rfind_cstr( const ALLEGRO_USTR * haystack, int start_pos,
const char * needle );
bool al_ustr_find_replace( ALLEGRO_USTR * us, int start_pos,
const ALLEGRO_USTR * find, const ALLEGRO_USTR * replace );
bool al_ustr_find_replace_cstr( ALLEGRO_USTR * us, int start_pos,
const char * find, const char * replace );
bool al_ustr_equal( const ALLEGRO_USTR * us1, const ALLEGRO_USTR * us2 );
int al_ustr_compare( const ALLEGRO_USTR * u, const ALLEGRO_USTR * v );
int al_ustr_ncompare( const ALLEGRO_USTR * us1, const ALLEGRO_USTR * us2,
int n );
bool al_ustr_has_prefix( const ALLEGRO_USTR * u, const ALLEGRO_USTR * v );
bool al_ustr_has_prefix_cstr( const ALLEGRO_USTR * u, const char * s );
bool al_ustr_has_suffix( const ALLEGRO_USTR * u, const ALLEGRO_USTR * v );
bool al_ustr_has_suffix_cstr( const ALLEGRO_USTR * us1, const char * s );
size_t al_utf8_width( int32_t c );
size_t al_utf8_encode( char s[], int32_t c );
ALLEGRO_USTR * al_ustr_new_from_utf16( uint16_t const * s );
size_t al_ustr_size_utf16( const ALLEGRO_USTR * us );
size_t al_ustr_encode_utf16( const ALLEGRO_USTR * us, uint16_t * s, size_t n );
size_t al_utf16_width( int c );
size_t al_utf16_encode( uint16_t s[], int32_t c );





/*** Folder allegro5\inline ***/



// fmaths.inl - Plik1
/* To nie jest plik nagłówhowy !!! */




/*** Folder allegro5\internal ***/



// aintern.h - Plik1
int _al_trace_handler( const char * msg );
void _al_add_exit_func( AL_METHOD( void, func,( void ) ), const char * desc );
void _al_remove_exit_func( AL_METHOD( void, func,( void ) ) );
void _al_run_exit_funcs( void );
void * _al_sane_realloc( void * ptr, size_t size );
char * _al_sane_strncpy( char * dest, const char * src, size_t n );
void _al_srand( int seed );
int _al_rand( void );
int _al_stricmp( const char * s1, const char * s2 );


// aintern_aatree.h - Plik2
// ***nie znaleziono żadnej funkcji***

// aintern_acodec_cfg.h - Plik3
// ***nie znaleziono żadnej funkcji***

// aintern_atomicops.h - Plik4
// ***nie znaleziono żadnej funkcji***

// aintern_audio.h - Plik5
int _al_kcm_get_silence( ALLEGRO_AUDIO_DEPTH depth );
void * _al_kcm_feed_stream( ALLEGRO_THREAD * self, void * vstream );
void _al_kcm_shutdown_default_mixer( void );
ALLEGRO_CHANNEL_CONF _al_count_to_channel_conf( int num_channels );
ALLEGRO_AUDIO_DEPTH _al_word_size_to_depth_conf( int word_size );


// aintern_audio_cfg.h - Plik6
// ***nie znaleziono żadnej funkcji***

// aintern_bitmap.h - Plik7
// ***nie znaleziono żadnej funkcji***

// aintern_blend.h - Plik8
// ***nie znaleziono żadnej funkcji***

// aintern_config.h - Plik9
// ***nie znaleziono żadnej funkcji***

// aintern_convert.h - Plik10
// ***nie znaleziono żadnej funkcji***

// aintern_direct3d.h - Plik11
void _al_d3d_set_blender( struct ALLEGRO_DISPLAY_D3D * disp );


// aintern_display.h - Plik12
void _al_set_display_invalidated_callback( ALLEGRO_DISPLAY * display,
void( * display_invalidated )( ALLEGRO_DISPLAY * ) );


// aintern_dtor.h - Plik13
_AL_DTOR_LIST * _al_init_destructors( void );
void _al_push_destructor_owner( void );
void _al_pop_destructor_owner( void );
void _al_run_destructors( _AL_DTOR_LIST * dtors );
void _al_shutdown_destructors( _AL_DTOR_LIST * dtors );
void _al_register_destructor( _AL_DTOR_LIST * dtors, void * object,
void( * func )( void * ) );
void _al_unregister_destructor( _AL_DTOR_LIST * dtors, void * object );
void _al_foreach_destructor( _AL_DTOR_LIST * dtors,
void( * callback )( void * object, void( * func )( void * ), void * udata ),
void * userdata );


// aintern_events.h - Plik14
void _al_init_events( void );
void _al_event_source_init( ALLEGRO_EVENT_SOURCE * );
void _al_event_source_free( ALLEGRO_EVENT_SOURCE * );
void _al_event_source_lock( ALLEGRO_EVENT_SOURCE * );
void _al_event_source_unlock( ALLEGRO_EVENT_SOURCE * );
void _al_event_source_on_registration_to_queue( ALLEGRO_EVENT_SOURCE *, ALLEGRO_EVENT_QUEUE * );
void _al_event_source_on_unregistration_from_queue( ALLEGRO_EVENT_SOURCE *, ALLEGRO_EVENT_QUEUE * );
bool _al_event_source_needs_to_generate_event( ALLEGRO_EVENT_SOURCE * );
void _al_event_source_emit_event( ALLEGRO_EVENT_SOURCE *, ALLEGRO_EVENT * );
void _al_event_queue_push_event( ALLEGRO_EVENT_QUEUE *, const ALLEGRO_EVENT * );


// aintern_file.h - Plik15
// ***nie znaleziono żadnej funkcji***

// aintern_float.h - Plik16
// ***nie znaleziono żadnej funkcji***

// aintern_fshook.h - Plik17
// ***nie znaleziono żadnej funkcji***

// aintern_gp2xwiz.h - Plik18
// ***nie znaleziono żadnej funkcji***

// aintern_image.h - Plik19
ALLEGRO_BITMAP * _al_iphone_load_image( const char * filename );
ALLEGRO_BITMAP * _al_iphone_load_image_f( ALLEGRO_FILE * f );
bool _al_osx_register_image_loader( void );
ALLEGRO_BITMAP * _al_load_pcx( const char * filename );
bool _al_save_pcx( const char * filename, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_pcx_f( ALLEGRO_FILE * f );
bool _al_save_pcx_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_bmp( const char * filename );
bool _al_save_bmp( const char * filename, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_bmp_f( ALLEGRO_FILE * f );
bool _al_save_bmp_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_tga( const char * filename );
bool _al_save_tga( const char * filename, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_tga_f( ALLEGRO_FILE * f );
bool _al_save_tga_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
bool _al_init_gdiplus( void );
void _al_shutdown_gdiplus( void );
ALLEGRO_BITMAP * _al_load_gdiplus_bitmap( const char * filename );
bool _al_save_gdiplus_bitmap( const char * filename, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_gdiplus_bitmap_f( ALLEGRO_FILE * f );
bool _al_save_gdiplus_png_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
bool _al_save_gdiplus_jpg_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
bool _al_save_gdiplus_tif_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
bool _al_save_gdiplus_gif_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_png( const char * filename );
bool _al_save_png( const char * filename, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_png_f( ALLEGRO_FILE * f );
bool _al_save_png_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_jpg( const char * filename );
bool _al_save_jpg( const char * filename, ALLEGRO_BITMAP * bmp );
ALLEGRO_BITMAP * _al_load_jpg_f( ALLEGRO_FILE * f );
bool _al_save_jpg_f( ALLEGRO_FILE * f, ALLEGRO_BITMAP * bmp );


// aintern_image_cfg.h - Plik20
// ***nie znaleziono żadnej funkcji***

// aintern_iphone.h - Plik21
// ***nie znaleziono żadnej funkcji***

// aintern_joystick.h - Plik22
// ***nie znaleziono żadnej funkcji***

// aintern_keyboard.h - Plik23
// ***nie znaleziono żadnej funkcji***

// aintern_list.h - Plik24
_AL_LIST * _al_list_create( void );
_AL_LIST * _al_list_create_static( size_t capacity );
void _al_list_destroy( _AL_LIST * list );
void _al_list_set_dtor( _AL_LIST * list, _AL_LIST_DTOR dtor );
_AL_LIST_DTOR _al_list_get_dtor( _AL_LIST * list );
_AL_LIST_ITEM * _al_list_push_front( _AL_LIST * list, void * data );
_AL_LIST_ITEM * _al_list_push_front_ex( _AL_LIST * list, void * data, _AL_LIST_ITEM_DTOR dtor );
_AL_LIST_ITEM * _al_list_push_back( _AL_LIST * list, void * data );
_AL_LIST_ITEM * _al_list_push_back_ex( _AL_LIST * list, void * data, _AL_LIST_ITEM_DTOR dtor );
void _al_list_pop_front( _AL_LIST * list );
void _al_list_pop_back( _AL_LIST * list );
_AL_LIST_ITEM * _al_list_insert_after( _AL_LIST * list, _AL_LIST_ITEM * where, void * data );
_AL_LIST_ITEM * _al_list_insert_after_ex( _AL_LIST * list, _AL_LIST_ITEM * where, void * data, _AL_LIST_ITEM_DTOR dtor );
_AL_LIST_ITEM * _al_list_insert_before( _AL_LIST * list, _AL_LIST_ITEM * where, void * data );
_AL_LIST_ITEM * _al_list_insert_before_ex( _AL_LIST * list, _AL_LIST_ITEM * where, void * data, _AL_LIST_ITEM_DTOR dtor );
void _al_list_erase( _AL_LIST * list, _AL_LIST_ITEM * item );
void _al_list_clear( _AL_LIST * list );
void _al_list_remove( _AL_LIST * list, void * data );
bool _al_list_is_empty( _AL_LIST * list );
bool _al_list_contains( _AL_LIST * list, void * data );
_AL_LIST_ITEM * _al_list_find_first( _AL_LIST * list, void * data );
_AL_LIST_ITEM * _al_list_find_last( _AL_LIST * list, void * data );
_AL_LIST_ITEM * _al_list_find_after( _AL_LIST * list, _AL_LIST_ITEM * where, void * data );
_AL_LIST_ITEM * _al_list_find_before( _AL_LIST * list, _AL_LIST_ITEM * where, void * data );
size_t _al_list_size( _AL_LIST * list );
_AL_LIST_ITEM * _al_list_at( _AL_LIST * list, size_t index );
_AL_LIST_ITEM * _al_list_front( _AL_LIST * list );
_AL_LIST_ITEM * _al_list_back( _AL_LIST * list );
_AL_LIST_ITEM * _al_list_next( _AL_LIST * list, _AL_LIST_ITEM * item );
_AL_LIST_ITEM * _al_list_previous( _AL_LIST * list, _AL_LIST_ITEM * item );
_AL_LIST_ITEM * _al_list_next_circular( _AL_LIST * list, _AL_LIST_ITEM * item );
_AL_LIST_ITEM * _al_list_previous_circular( _AL_LIST * list, _AL_LIST_ITEM * item );
void * _al_list_item_data( _AL_LIST_ITEM * item );
void _al_list_item_set_dtor( _AL_LIST_ITEM * item, _AL_LIST_ITEM_DTOR dtor );
_AL_LIST_ITEM_DTOR _al_list_item_get_dtor( _AL_LIST_ITEM * item );
void _al_list_set_user_data( _AL_LIST * list, void * user_data );
void * _al_list_get_user_data( _AL_LIST * list );


// aintern_mouse.h - Plik25
// ***nie znaleziono żadnej funkcji***

// aintern_native_dialog.h - Plik26
// ***nie znaleziono żadnej funkcji***

// aintern_native_dialog_cfg.h - Plik27
// ***nie znaleziono żadnej funkcji***

// aintern_opengl.h - Plik28
// ***nie znaleziono żadnej funkcji***

// aintern_path.h - Plik29
// ***nie znaleziono żadnej funkcji***

// aintern_pixels.h - Plik30
char const * _al_format_name( ALLEGRO_PIXEL_FORMAT format );
void _al_init_pixels( void );


// aintern_prim.h - Plik31
// ***nie znaleziono żadnej funkcji***

// aintern_prim_directx.h - Plik32
// ***nie znaleziono żadnej funkcji***

// aintern_prim_opengl.h - Plik33
// ***nie znaleziono żadnej funkcji***

// aintern_prim_soft.h - Plik34
// ***nie znaleziono żadnej funkcji***

// aintern_system.h - Plik35
void _al_register_system_interfaces( void );
void * _al_open_library( const char * filename );
void * _al_import_symbol( void * library, const char * symbol );
void _al_close_library( void * library );


// aintern_thread.h - Plik36
void _al_thread_create( _AL_THREAD *,
void( * proc )( _AL_THREAD *, void * ),
void * arg );
void _al_thread_set_should_stop( _AL_THREAD * );
void _al_thread_join( _AL_THREAD * );
void _al_thread_detach( _AL_THREAD * );
void _al_mutex_init( _AL_MUTEX * );
void _al_mutex_init_recursive( _AL_MUTEX * );
void _al_mutex_destroy( _AL_MUTEX * );
void _al_cond_init( _AL_COND * );
void _al_cond_destroy( _AL_COND * );
void _al_cond_wait( _AL_COND *, _AL_MUTEX * );
void _al_cond_broadcast( _AL_COND * );
void _al_cond_signal( _AL_COND * );
int _al_cond_timedwait( _AL_COND *, _AL_MUTEX *, const ALLEGRO_TIMEOUT * timeout );


// aintern_timer.h - Plik37
// ***nie znaleziono żadnej funkcji***

// aintern_tls.h - Plik38
// ***nie znaleziono żadnej funkcji***

// aintern_tri_soft.h - Plik39
void _al_triangle_2d( ALLEGRO_BITMAP * texture, ALLEGRO_VERTEX * v1, ALLEGRO_VERTEX * v2, ALLEGRO_VERTEX * v3 );
void _al_draw_soft_triangle(
ALLEGRO_VERTEX * v1, ALLEGRO_VERTEX * v2, ALLEGRO_VERTEX * v3, uintptr_t state,
void( * init )( uintptr_t, ALLEGRO_VERTEX *, ALLEGRO_VERTEX *, ALLEGRO_VERTEX * ),
void( * first )( uintptr_t, int, int, int, int ),
void( * step )( uintptr_t, int ),
void( * draw )( uintptr_t, int, int, int ) );


// aintern_ttf_cfg.h - Plik40
// ***nie znaleziono żadnej funkcji***

// aintern_vector.h - Plik41
void _al_vector_init( _AL_VECTOR *, size_t itemsize );
void * _al_vector_ref( const _AL_VECTOR *, unsigned int index );
void * _al_vector_ref_front( const _AL_VECTOR * );
void * _al_vector_ref_back( const _AL_VECTOR * );
bool _al_vector_append_array( _AL_VECTOR * vec, unsigned int num, const void * arr );
void * _al_vector_alloc_back( _AL_VECTOR * );
void * _al_vector_alloc_mid( _AL_VECTOR *, unsigned int index );
int _al_vector_find( const _AL_VECTOR *, const void * ptr_item );
bool _al_vector_contains( const _AL_VECTOR *, const void * ptr_item );
void _al_vector_delete_at( _AL_VECTOR *, unsigned int index );
bool _al_vector_find_and_delete( _AL_VECTOR *, const void * ptr_item );
void _al_vector_free( _AL_VECTOR * );


// wgl_ext_defs.h - Plik11
// ***nie znaleziono żadnej funkcji***

// wgl_ext_list.h - Plik12
// ***nie znaleziono żadnej funkcji***




/*** Folder allegro5\platform ***/



// aintiphone.h - Plik1
// ***nie znaleziono żadnej funkcji***

// aintlnx.h - Plik2
// ***nie znaleziono żadnej funkcji***

// aintosx.h - Plik3
ALLEGRO_KEYBOARD_DRIVER * _al_osx_get_keyboard_driver( void );
ALLEGRO_DISPLAY_INTERFACE * _al_osx_get_display_driver( void );
ALLEGRO_MOUSE_DRIVER * _al_osx_get_mouse_driver( void );
ALLEGRO_JOYSTICK_DRIVER * _al_osx_get_joystick_driver( void );
int _al_osx_run_main( int argc, char ** argv,
int( * real_main )( int, char ** ) );


// aintunix.h - Plik4
ALLEGRO_PATH * _al_unix_get_path( int id );
void _unix_load_modules( int system_driver_id );
void _unix_unload_modules( void );
void _unix_driver_lists_init( void );
void _unix_driver_lists_shutdown( void );
void _al_unix_init_time( void );


// aintuthr.h - Plik5
void _al_mutex_init( struct _AL_MUTEX * );
void _al_mutex_destroy( struct _AL_MUTEX * );


// aintwin.h - Plik6
void _al_win_wnd_schedule_proc( HWND wnd, void( * proc )( void * ), void * param );
void _al_win_wnd_call_proc( HWND wnd, void( * proc )( void * ), void * param );


// aintwiz.h - Plik7
// ***nie znaleziono żadnej funkcji***

// aintwthr.h - Plik8
// ***nie znaleziono żadnej funkcji***

// aintxglx.h - Plik9
// ***nie znaleziono żadnej funkcji***

// al386gcc.h - Plik10
// ***nie znaleziono żadnej funkcji***

// al386vc.h - Plik11
// ***nie znaleziono żadnej funkcji***

// al386wat.h - Plik12
// ***nie znaleziono żadnej funkcji***

// albcc32.h - Plik13
// ***nie znaleziono żadnej funkcji***

// aldmc.h - Plik14
// ***nie znaleziono żadnej funkcji***

// aliphone.h - Plik15
// ***nie znaleziono żadnej funkcji***

// aliphonecfg.h - Plik16
// ***nie znaleziono żadnej funkcji***

// almngw32.h - Plik17
// ***nie znaleziono żadnej funkcji***

// almsvc.h - Plik18
// ***nie znaleziono żadnej funkcji***

// alosx.h - Plik19
// ***nie znaleziono żadnej funkcji***

// alosxcfg.h - Plik20
// ***nie znaleziono żadnej funkcji***

// alplatf.h - Plik21
// ***nie znaleziono żadnej funkcji***

// alucfg.h - Plik22
// ***nie znaleziono żadnej funkcji***

// alunix.h - Plik23
// ***nie znaleziono żadnej funkcji***

// alwatcom.h - Plik24
// ***nie znaleziono żadnej funkcji***

// alwin.h - Plik25
int _WinMain( void * _main, void * hInst, void * hPrev, char * Cmd, int nShow );


// alwiz.h - Plik26
// ***nie znaleziono żadnej funkcji***

// alwizcfg.h - Plik27
// ***nie znaleziono żadnej funkcji***

// astdbool.h - Plik28
// ***nie znaleziono żadnej funkcji***

// astdint.h - Plik29
// ***nie znaleziono żadnej funkcji***

#endif // PROTOTIPOS_H_INCLUDED
