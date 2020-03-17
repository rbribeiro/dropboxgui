/* ShareView.c generated by valac 0.40.19, the Vala compiler
 * generated from ShareView.vala, do not modify */



#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <pango/pango.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define TYPE_SHARE_VIEW (share_view_get_type ())
#define SHARE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_SHARE_VIEW, ShareView))
#define SHARE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_SHARE_VIEW, ShareViewClass))
#define IS_SHARE_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_SHARE_VIEW))
#define IS_SHARE_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_SHARE_VIEW))
#define SHARE_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_SHARE_VIEW, ShareViewClass))

typedef struct _ShareView ShareView;
typedef struct _ShareViewClass ShareViewClass;
typedef struct _ShareViewPrivate ShareViewPrivate;
enum  {
	SHARE_VIEW_0_PROPERTY,
	SHARE_VIEW_NUM_PROPERTIES
};
static GParamSpec* share_view_properties[SHARE_VIEW_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _ShareView {
	GtkGrid parent_instance;
	ShareViewPrivate * priv;
};

struct _ShareViewClass {
	GtkGridClass parent_class;
};

struct _ShareViewPrivate {
	GtkImage* new_document;
	GtkLabel* share_link;
	GtkLabel* file_name;
	GtkButton* clear_button;
};


static gpointer share_view_parent_class = NULL;

GType share_view_get_type (void) G_GNUC_CONST;
#define SHARE_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_SHARE_VIEW, ShareViewPrivate))
ShareView* share_view_new (void);
ShareView* share_view_construct (GType object_type);
static void share_view_on_drag_drop (ShareView* self,
                              GtkWidget* widget,
                              GdkDragContext* context,
                              gint x,
                              gint y,
                              GtkSelectionData* data,
                              guint info,
                              guint time);
static void _share_view_on_drag_drop_gtk_widget_drag_data_received (GtkWidget* _sender,
                                                             GdkDragContext* context,
                                                             gint x,
                                                             gint y,
                                                             GtkSelectionData* selection_data,
                                                             guint info,
                                                             guint time_,
                                                             gpointer self);
static void share_view_clear_link (ShareView* self);
static void _share_view_clear_link_gtk_button_clicked (GtkButton* _sender,
                                                gpointer self);
static void share_view_gen_new_link (ShareView* self,
                              const gchar* file_uri);
gchar* dropbox_gen_share_link (const gchar* path);
static void share_view_finalize (GObject * obj);
static void _vala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);

static const GtkTargetEntry SHARE_VIEW_targets[1] = {{"text/uri-list", (guint) 0, (guint) 0}};

static void
_share_view_on_drag_drop_gtk_widget_drag_data_received (GtkWidget* _sender,
                                                        GdkDragContext* context,
                                                        gint x,
                                                        gint y,
                                                        GtkSelectionData* selection_data,
                                                        guint info,
                                                        guint time_,
                                                        gpointer self)
{
#line 22 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	share_view_on_drag_drop ((ShareView*) self, _sender, context, x, y, selection_data, info, time_);
#line 103 "ShareView.c"
}


static void
_share_view_clear_link_gtk_button_clicked (GtkButton* _sender,
                                           gpointer self)
{
#line 36 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	share_view_clear_link ((ShareView*) self);
#line 113 "ShareView.c"
}


ShareView*
share_view_construct (GType object_type)
{
	ShareView * self = NULL;
	GtkImage* _tmp0_;
	GtkImage* _tmp1_;
	GtkImage* _tmp2_;
	GtkImage* _tmp3_;
	GtkLabel* _tmp4_;
	GtkLabel* _tmp5_;
	GtkLabel* _tmp6_;
	GtkLabel* _tmp7_;
	GtkLabel* _tmp8_;
	GtkLabel* _tmp9_;
	GtkLabel* _tmp10_;
	GtkLabel* _tmp11_;
	GtkLabel* _tmp12_;
	GtkButton* _tmp13_;
	GtkButton* _tmp14_;
	GtkButton* _tmp15_;
	GtkButton* _tmp16_;
	GtkStyleContext* _tmp17_;
	GtkButton* _tmp18_;
	GtkImage* _tmp19_;
	GtkLabel* _tmp20_;
	GtkLabel* _tmp21_;
#line 8 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self = (ShareView*) g_object_new (object_type, NULL);
#line 10 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_orientable_set_orientation ((GtkOrientable*) self, GTK_ORIENTATION_VERTICAL);
#line 11 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_widget_set_margin_bottom ((GtkWidget*) self, 24);
#line 12 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_widget_set_valign ((GtkWidget*) self, GTK_ALIGN_CENTER);
#line 12 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_widget_set_halign ((GtkWidget*) self, GTK_ALIGN_CENTER);
#line 14 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_grid_set_row_spacing ((GtkGrid*) self, 12);
#line 17 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp0_ = (GtkImage*) gtk_image_new_from_icon_name ("document-new-symbolic", (GtkIconSize) GTK_ICON_SIZE_DIALOG);
#line 17 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_ref_sink (_tmp0_);
#line 17 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->new_document);
#line 17 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self->priv->new_document = _tmp0_;
#line 18 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp1_ = self->priv->new_document;
#line 18 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_image_set_pixel_size (_tmp1_, 128);
#line 20 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp2_ = self->priv->new_document;
#line 20 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_drag_dest_set ((GtkWidget*) _tmp2_, GTK_DEST_DEFAULT_ALL, SHARE_VIEW_targets, G_N_ELEMENTS (SHARE_VIEW_targets), GDK_ACTION_COPY);
#line 22 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp3_ = self->priv->new_document;
#line 22 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_signal_connect_object ((GtkWidget*) _tmp3_, "drag-data-received", (GCallback) _share_view_on_drag_drop_gtk_widget_drag_data_received, self, 0);
#line 24 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp4_ = (GtkLabel*) gtk_label_new ("");
#line 24 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_ref_sink (_tmp4_);
#line 24 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->file_name);
#line 24 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self->priv->file_name = _tmp4_;
#line 26 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp5_ = (GtkLabel*) gtk_label_new ("Generate share link");
#line 26 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_ref_sink (_tmp5_);
#line 26 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->share_link);
#line 26 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self->priv->share_link = _tmp5_;
#line 27 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp6_ = self->priv->share_link;
#line 27 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp7_ = self->priv->file_name;
#line 27 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_use_markup (_tmp7_, TRUE);
#line 27 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_use_markup (_tmp6_, TRUE);
#line 28 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp8_ = self->priv->share_link;
#line 28 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp9_ = self->priv->file_name;
#line 28 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_ellipsize (_tmp9_, PANGO_ELLIPSIZE_END);
#line 28 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_ellipsize (_tmp8_, PANGO_ELLIPSIZE_END);
#line 29 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp10_ = self->priv->share_link;
#line 29 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp11_ = self->priv->file_name;
#line 29 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_max_width_chars (_tmp11_, 32);
#line 29 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_max_width_chars (_tmp10_, 32);
#line 30 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp12_ = self->priv->share_link;
#line 30 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_use_underline (_tmp12_, TRUE);
#line 32 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp13_ = (GtkButton*) gtk_button_new_with_label ("Clear");
#line 32 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_ref_sink (_tmp13_);
#line 32 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->clear_button);
#line 32 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self->priv->clear_button = _tmp13_;
#line 33 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp14_ = self->priv->clear_button;
#line 33 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_widget_set_hexpand_set ((GtkWidget*) _tmp14_, FALSE);
#line 34 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp15_ = self->priv->clear_button;
#line 34 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_set ((GtkWidget*) _tmp15_, "expand", FALSE, NULL);
#line 35 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp16_ = self->priv->clear_button;
#line 35 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp17_ = gtk_widget_get_style_context ((GtkWidget*) _tmp16_);
#line 35 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_style_context_add_class (_tmp17_, GTK_STYLE_CLASS_DESTRUCTIVE_ACTION);
#line 36 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp18_ = self->priv->clear_button;
#line 36 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_signal_connect_object (_tmp18_, "clicked", (GCallback) _share_view_clear_link_gtk_button_clicked, self, 0);
#line 38 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp19_ = self->priv->new_document;
#line 38 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp19_);
#line 39 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp20_ = self->priv->file_name;
#line 39 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp20_);
#line 40 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp21_ = self->priv->share_link;
#line 40 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp21_);
#line 8 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	return self;
#line 259 "ShareView.c"
}


ShareView*
share_view_new (void)
{
#line 8 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	return share_view_construct (TYPE_SHARE_VIEW);
#line 268 "ShareView.c"
}


static void
share_view_clear_link (ShareView* self)
{
	GtkImage* _tmp0_;
	GtkLabel* _tmp1_;
	GtkLabel* _tmp2_;
	GtkButton* _tmp3_;
#line 44 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (self != NULL);
#line 45 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp0_ = self->priv->new_document;
#line 45 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_set (_tmp0_, "icon-name", "document-new-symbolic", NULL);
#line 46 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp1_ = self->priv->file_name;
#line 46 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_label (_tmp1_, "");
#line 47 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp2_ = self->priv->share_link;
#line 47 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_label (_tmp2_, "Generate sharelink");
#line 48 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp3_ = self->priv->clear_button;
#line 48 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_widget_set_visible ((GtkWidget*) _tmp3_, FALSE);
#line 297 "ShareView.c"
}


static gchar*
string_slice (const gchar* self,
              glong start,
              glong end)
{
	gchar* result = NULL;
	glong string_length = 0L;
	gint _tmp0_;
	gint _tmp1_;
	gboolean _tmp4_ = FALSE;
	gboolean _tmp6_ = FALSE;
	gchar* _tmp8_;
#line 1425 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (self != NULL, NULL);
#line 1426 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp0_ = strlen (self);
#line 1426 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = _tmp0_;
#line 1426 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	string_length = (glong) _tmp1_;
#line 1427 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (start < ((glong) 0)) {
#line 323 "ShareView.c"
		glong _tmp2_;
#line 1428 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp2_ = string_length;
#line 1428 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		start = _tmp2_ + start;
#line 329 "ShareView.c"
	}
#line 1430 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (end < ((glong) 0)) {
#line 333 "ShareView.c"
		glong _tmp3_;
#line 1431 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp3_ = string_length;
#line 1431 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		end = _tmp3_ + end;
#line 339 "ShareView.c"
	}
#line 1433 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (start >= ((glong) 0)) {
#line 343 "ShareView.c"
		glong _tmp5_;
#line 1433 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp5_ = string_length;
#line 1433 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp4_ = start <= _tmp5_;
#line 349 "ShareView.c"
	} else {
#line 1433 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp4_ = FALSE;
#line 353 "ShareView.c"
	}
#line 1433 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (_tmp4_, NULL);
#line 1434 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	if (end >= ((glong) 0)) {
#line 359 "ShareView.c"
		glong _tmp7_;
#line 1434 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp7_ = string_length;
#line 1434 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp6_ = end <= _tmp7_;
#line 365 "ShareView.c"
	} else {
#line 1434 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
		_tmp6_ = FALSE;
#line 369 "ShareView.c"
	}
#line 1434 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (_tmp6_, NULL);
#line 1435 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	g_return_val_if_fail (start <= end, NULL);
#line 1436 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp8_ = g_strndup (((gchar*) self) + start, (gsize) (end - start));
#line 1436 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp8_;
#line 1436 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 381 "ShareView.c"
}


static void
share_view_gen_new_link (ShareView* self,
                         const gchar* file_uri)
{
	gchar* file_absolut_path = NULL;
	gint _tmp0_;
	gint _tmp1_;
	gchar* _tmp2_;
	gchar* url = NULL;
	gchar* _tmp3_;
	GtkLabel* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gint _tmp9_;
	gint _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
#line 51 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (self != NULL);
#line 51 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (file_uri != NULL);
#line 52 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp0_ = strlen (file_uri);
#line 52 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp1_ = _tmp0_;
#line 52 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp2_ = string_slice (file_uri, (glong) 7, (glong) _tmp1_);
#line 52 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	file_absolut_path = _tmp2_;
#line 54 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp3_ = dropbox_gen_share_link (file_absolut_path);
#line 54 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	url = _tmp3_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp4_ = self->priv->share_link;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp5_ = g_strconcat ("<a href=\"", url, NULL);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp6_ = _tmp5_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp7_ = g_strconcat (_tmp6_, "\">", NULL);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp8_ = _tmp7_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp9_ = strlen (url);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp10_ = _tmp9_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp11_ = string_slice (url, (glong) 12, (glong) _tmp10_);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp12_ = _tmp11_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp13_ = g_strconcat (_tmp8_, _tmp12_, NULL);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp14_ = _tmp13_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp15_ = g_strconcat (_tmp14_, "</a>", NULL);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp16_ = _tmp15_;
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_label (_tmp4_, _tmp16_);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp16_);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp14_);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp12_);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp8_);
#line 55 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp6_);
#line 51 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (url);
#line 51 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (file_absolut_path);
#line 466 "ShareView.c"
}


static void
share_view_on_drag_drop (ShareView* self,
                         GtkWidget* widget,
                         GdkDragContext* context,
                         gint x,
                         gint y,
                         GtkSelectionData* data,
                         guint info,
                         guint time)
{
	GtkImage* _tmp0_;
	GFile* file = NULL;
	gchar** _tmp1_;
	gchar** _tmp2_;
	gchar** _tmp3_;
	gint _tmp3__length1;
	const gchar* _tmp4_;
	GFile* _tmp5_;
	GFile* _tmp6_;
	GtkLabel* _tmp7_;
	GFile* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* _tmp13_;
	gchar* _tmp14_;
	gchar** _tmp15_;
	gchar** _tmp16_;
	gchar** _tmp17_;
	gint _tmp17__length1;
	const gchar* _tmp18_;
	GtkImage* _tmp19_;
	GList* _tmp20_;
	GList* _tmp21_;
	gboolean _tmp22_;
#line 58 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (self != NULL);
#line 58 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (widget != NULL);
#line 58 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (context != NULL);
#line 58 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_return_if_fail (data != NULL);
#line 59 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp0_ = self->priv->new_document;
#line 59 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_set (_tmp0_, "icon-name", "image-loading-symbolic", NULL);
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp2_ = _tmp1_ = gtk_selection_data_get_uris (data);
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp3_ = _tmp2_;
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp3__length1 = _vala_array_length (_tmp1_);
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp4_ = _tmp3_[0];
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp5_ = g_file_new_for_uri (_tmp4_);
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp6_ = _tmp5_;
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp3_ = (_vala_array_free (_tmp3_, _tmp3__length1, (GDestroyNotify) g_free), NULL);
#line 61 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	file = _tmp6_;
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp7_ = self->priv->file_name;
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp8_ = file;
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp9_ = g_file_get_basename (_tmp8_);
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp10_ = _tmp9_;
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp11_ = g_strconcat ("<b>", _tmp10_, NULL);
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp12_ = _tmp11_;
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp13_ = g_strconcat (_tmp12_, "</b>", NULL);
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp14_ = _tmp13_;
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	gtk_label_set_label (_tmp7_, _tmp14_);
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp14_);
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp12_);
#line 63 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_free0 (_tmp10_);
#line 65 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp16_ = _tmp15_ = gtk_selection_data_get_uris (data);
#line 65 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp17_ = _tmp16_;
#line 65 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp17__length1 = _vala_array_length (_tmp15_);
#line 65 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp18_ = _tmp17_[0];
#line 65 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	share_view_gen_new_link (self, _tmp18_);
#line 65 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp17_ = (_vala_array_free (_tmp17_, _tmp17__length1, (GDestroyNotify) g_free), NULL);
#line 66 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp19_ = self->priv->new_document;
#line 66 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_object_set (_tmp19_, "icon-name", "process-completed", NULL);
#line 68 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp20_ = gtk_container_get_children ((GtkContainer*) self);
#line 68 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp21_ = _tmp20_;
#line 68 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_tmp22_ = g_list_length (_tmp21_) == ((guint) 3);
#line 68 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	(_tmp21_ == NULL) ? NULL : (_tmp21_ = (g_list_free (_tmp21_), NULL));
#line 68 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	if (_tmp22_) {
#line 584 "ShareView.c"
		GtkButton* _tmp23_;
		GtkButton* _tmp24_;
#line 69 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
		_tmp23_ = self->priv->clear_button;
#line 69 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
		gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp23_);
#line 70 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
		_tmp24_ = self->priv->clear_button;
#line 70 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
		gtk_widget_set_visible ((GtkWidget*) _tmp24_, TRUE);
#line 595 "ShareView.c"
	} else {
		GtkButton* _tmp25_;
#line 72 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
		_tmp25_ = self->priv->clear_button;
#line 72 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
		gtk_widget_set_visible ((GtkWidget*) _tmp25_, TRUE);
#line 602 "ShareView.c"
	}
#line 58 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (file);
#line 606 "ShareView.c"
}


static void
share_view_class_init (ShareViewClass * klass)
{
#line 1 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	share_view_parent_class = g_type_class_peek_parent (klass);
#line 1 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	g_type_class_add_private (klass, sizeof (ShareViewPrivate));
#line 1 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	G_OBJECT_CLASS (klass)->finalize = share_view_finalize;
#line 619 "ShareView.c"
}


static void
share_view_instance_init (ShareView * self)
{
#line 1 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self->priv = SHARE_VIEW_GET_PRIVATE (self);
#line 628 "ShareView.c"
}


static void
share_view_finalize (GObject * obj)
{
	ShareView * self;
#line 1 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_SHARE_VIEW, ShareView);
#line 2 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->new_document);
#line 3 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->share_link);
#line 4 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->file_name);
#line 5 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	_g_object_unref0 (self->priv->clear_button);
#line 1 "/home/rodrigo/Public/dropboxgui/src/Views/ShareView.vala"
	G_OBJECT_CLASS (share_view_parent_class)->finalize (obj);
#line 648 "ShareView.c"
}


GType
share_view_get_type (void)
{
	static volatile gsize share_view_type_id__volatile = 0;
	if (g_once_init_enter (&share_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ShareViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) share_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (ShareView), 0, (GInstanceInitFunc) share_view_instance_init, NULL };
		GType share_view_type_id;
		share_view_type_id = g_type_register_static (gtk_grid_get_type (), "ShareView", &g_define_type_info, 0);
		g_once_init_leave (&share_view_type_id__volatile, share_view_type_id);
	}
	return share_view_type_id__volatile;
}


static void
_vala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void
_vala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint
_vala_array_length (gpointer array)
{
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



