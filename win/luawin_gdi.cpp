#include "luawin.h"

//------------------------------------------------------------------------------------------------
int load_gdi(lua_State* L)
{
#if defined(BIND_GDI)

    xlb_module(L, MODULE_NAME) ({
        xlb_f("AbortPath", AbortPath),
        xlb_f("AddFontMemResourceEx", AddFontMemResourceEx),
        xlb_f("AddFontResource", AddFontResource),
        xlb_f("AddFontResourceEx", AddFontResourceEx),
        xlb_f("AlphaBlend", AlphaBlend),
        xlb_f("AngleArc", AngleArc),
        xlb_f("AnimatePalette", AnimatePalette),
        xlb_f("Arc", Arc),
        xlb_f("ArcTo", ArcTo),
        xlb_f("BeginPaint", BeginPaint),
        xlb_f("BeginPath", BeginPath),
        xlb_f("BitBlt", BitBlt),
        xlb_f("CancelDC", CancelDC),
        xlb_class<xlb_cbf<CFP_ALLOCPROC>>("CFP_ALLOCPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<CFP_FREEPROC>>("CFP_FREEPROC").constructor<xlb_luafunc>(),
        xlb_class<xlb_cbf<CFP_REALLOCPROC>>("CFP_REALLOCPROC").constructor<xlb_luafunc>(),
        xlb_f("ChangeDisplaySettings", ChangeDisplaySettings),
        xlb_f("ChangeDisplaySettingsEx", ChangeDisplaySettingsEx),
        xlb_f("Chord", Chord),
        xlb_f("ClientToScreen", ClientToScreen),
        xlb_f("CloseEnhMetaFile", CloseEnhMetaFile),
        xlb_f("CloseFigure", CloseFigure),
        xlb_f("CloseMetaFile", CloseMetaFile),
        xlb_f("CombineRgn", CombineRgn),
        xlb_f("CombineTransform", CombineTransform),
        xlb_f("CopyEnhMetaFile", CopyEnhMetaFile),
        xlb_f("CopyMetaFile", CopyMetaFile),
        xlb_f("CopyRect", CopyRect),
        xlb_f("CreateBitmap", CreateBitmap),
        xlb_f("CreateBitmapIndirect", CreateBitmapIndirect),
        xlb_f("CreateBrushIndirect", CreateBrushIndirect),
        xlb_f("CreateCompatibleBitmap", CreateCompatibleBitmap),
        xlb_f("CreateCompatibleDC", CreateCompatibleDC),
        xlb_f("CreateDCA", CreateDCA),
        xlb_f("CreateDCW", CreateDCW),
        xlb_f("CreateDIBitmap", CreateDIBitmap),
        xlb_f("CreateDIBPatternBrush", CreateDIBPatternBrush),
        xlb_f("CreateDIBPatternBrushPt", CreateDIBPatternBrushPt),
        xlb_f("CreateDIBSection", CreateDIBSection),
        xlb_f("CreateDiscardableBitmap", CreateDiscardableBitmap),
        xlb_f("CreateEllipticRgn", CreateEllipticRgn),
        xlb_f("CreateEllipticRgnIndirect", CreateEllipticRgnIndirect),
        xlb_f("CreateEnhMetaFile", CreateEnhMetaFile),
        xlb_f("CreateFont", CreateFont),
        xlb_f("CreateFontIndirect", CreateFontIndirect),
        xlb_f("CreateFontIndirectEx", CreateFontIndirectEx),
        xlb_f("CreateFontPackage", CreateFontPackage),
        xlb_f("CreateHalftonePalette", CreateHalftonePalette),
        xlb_f("CreateHatchBrush", CreateHatchBrush),
        xlb_f("CreateICA", CreateICA),
        xlb_f("CreateICW", CreateICW),
        xlb_f("CreateMetaFile", CreateMetaFile),
        xlb_f("CreatePalette", CreatePalette),
        xlb_f("CreatePatternBrush", CreatePatternBrush),
        xlb_f("CreatePen", CreatePen),
        xlb_f("CreatePenIndirect", CreatePenIndirect),
        xlb_f("CreatePolygonRgn", CreatePolygonRgn),
        xlb_f("CreatePolyPolygonRgn", CreatePolyPolygonRgn),
        xlb_f("CreateRectRgn", CreateRectRgn),
        xlb_f("CreateRectRgnIndirect", CreateRectRgnIndirect),
        xlb_f("CreateRoundRectRgn", CreateRoundRectRgn),
        xlb_f("CreateScalableFontResource", CreateScalableFontResource),
        xlb_f("CreateSolidBrush", CreateSolidBrush),
        xlb_f("DeleteDC", DeleteDC),
        xlb_f("DeleteEnhMetaFile", DeleteEnhMetaFile),
        xlb_f("DeleteFont", [](HFONT hfont)->void { DeleteObject((HGDIOBJ)(HFONT)(hfont)); }),
        xlb_f("DeleteMetaFile", DeleteMetaFile),
        xlb_f("DeleteObject", DeleteObject),
        xlb_f("DIBINDEX", [](int n) { return DIBINDEX(n); }),
        xlb_f("DPtoLP", DPtoLP),
        xlb_f("DrawAnimatedRects", DrawAnimatedRects),
        xlb_f("DrawCaption", DrawCaption),
        xlb_f("DrawEdge", DrawEdge),
        xlb_f("DrawEscape", DrawEscape),
        xlb_f("DrawFocusRect", DrawFocusRect),
        xlb_f("DrawFrameControl", DrawFrameControl),
        xlb_f("DrawState", DrawState),
        xlb_class<xlb_cbf<DRAWSTATEPROC>>("DRAWSTATEPROC").constructor<xlb_luafunc>(),
        xlb_f("DrawText", DrawText),
        xlb_f("DrawTextEx", DrawTextEx),
        xlb_f("Ellipse", Ellipse),
        xlb_f("EndPaint", EndPaint),
        xlb_f("EndPath", EndPath),
        xlb_class<xlb_cbf<ENHMFENUMPROC>>("ENHMFENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("EnumDisplayDevices", EnumDisplayDevices),
        xlb_f("EnumDisplayMonitors", EnumDisplayMonitors),
        xlb_f("EnumDisplaySettings", EnumDisplaySettings),
        xlb_f("EnumDisplaySettingsEx", EnumDisplaySettingsEx),
        xlb_f("EnumEnhMetaFile", EnumEnhMetaFile),
        xlb_f("EnumFontFamilies", EnumFontFamilies),
        xlb_f("EnumFontFamiliesEx", EnumFontFamiliesEx),
        xlb_f("EnumFonts", EnumFonts),
        xlb_f("EnumMetaFile", EnumMetaFile),
        xlb_f("EnumObjects", EnumObjects),
        xlb_f("EqualRect", EqualRect),
        xlb_f("EqualRgn", EqualRgn),
        xlb_f("ExcludeClipRect", ExcludeClipRect),
        xlb_f("ExcludeUpdateRgn", ExcludeUpdateRgn),
        xlb_f("ExtCreatePen", ExtCreatePen),
        xlb_f("ExtCreateRegion", ExtCreateRegion),
        xlb_f("ExtFloodFill", ExtFloodFill),
        xlb_f("ExtSelectClipRgn", ExtSelectClipRgn),
        xlb_f("ExtTextOut", ExtTextOut),
        xlb_f("FillPath", FillPath),
        xlb_f("FillRect", FillRect),
        xlb_f("FillRgn", FillRgn),
        xlb_f("FlattenPath", FlattenPath),
        xlb_f("FloodFill", FloodFill),
        xlb_f("FrameRect", FrameRect),
        xlb_f("FrameRgn", FrameRgn),
        xlb_f("GdiAlphaBlend", GdiAlphaBlend),
        xlb_f("GdiComment", GdiComment),
        xlb_f("GdiFlush", GdiFlush),
        xlb_f("GdiGetBatchLimit", GdiGetBatchLimit),
        xlb_f("GdiGradientFill", GdiGradientFill),
        xlb_f("GdiSetBatchLimit", GdiSetBatchLimit),
        xlb_f("GdiTransparentBlt", GdiTransparentBlt),
        xlb_f("GetArcDirection", GetArcDirection),
        xlb_f("GetAspectRatioFilterEx", GetAspectRatioFilterEx),
        xlb_f("GetBitmapBits", GetBitmapBits),
        xlb_f("GetBitmapDimensionEx", GetBitmapDimensionEx),
        xlb_f("GetBkColor", GetBkColor),
        xlb_f("GetBkMode", GetBkMode),
        xlb_f("GetBoundsRect", GetBoundsRect),
        xlb_f("GetBrushOrgEx", GetBrushOrgEx),
        xlb_f("GetBValue", [](COLORREF rgb) { return GetBValue(rgb); }),
        xlb_f("GetCharABCWidths", GetCharABCWidths),
        xlb_f("GetCharABCWidthsFloat", GetCharABCWidthsFloat),
        xlb_f("GetCharABCWidthsI", GetCharABCWidthsI),
        xlb_f("GetCharacterPlacement", GetCharacterPlacement),
        xlb_f("GetCharWidth32A", GetCharWidth32A),
        xlb_f("GetCharWidth32W", GetCharWidth32W),
        xlb_f("GetCharWidth", GetCharWidth),
        xlb_f("GetCharWidthFloat", GetCharWidthFloat),
        xlb_f("GetCharWidthI", GetCharWidthI),
        xlb_f("GetClipBox", GetClipBox),
        xlb_f("GetClipRgn", GetClipRgn),
        xlb_f("GetColorAdjustment", GetColorAdjustment),
        xlb_f("GetCurrentObject", GetCurrentObject),
        xlb_f("GetCurrentPositionEx", GetCurrentPositionEx),
        xlb_f("GetDC", GetDC),
        xlb_f("GetDCBrushColor", GetDCBrushColor),
        xlb_f("GetDCEx", GetDCEx),
        xlb_f("GetDCOrgEx", GetDCOrgEx),
        xlb_f("GetDCPenColor", GetDCPenColor),
        xlb_f("GetDeviceCaps", GetDeviceCaps),
        xlb_f("GetDIBColorTable", GetDIBColorTable),
        xlb_f("GetDIBits", GetDIBits),
        xlb_f("GetEnhMetaFile", GetEnhMetaFile),
        xlb_f("GetEnhMetaFileBits", GetEnhMetaFileBits),
        xlb_f("GetEnhMetaFileDescription", GetEnhMetaFileDescription),
        xlb_f("GetEnhMetaFileHeader", GetEnhMetaFileHeader),
        xlb_f("GetEnhMetaFilePaletteEntries", GetEnhMetaFilePaletteEntries),
        xlb_f("GetFontData", GetFontData),
        xlb_f("GetFontLanguageInfo", GetFontLanguageInfo),
        xlb_f("GetFontUnicodeRanges", GetFontUnicodeRanges),
        xlb_f("GetGlyphIndices", GetGlyphIndices),
        xlb_f("GetGlyphOutline", GetGlyphOutline),
        xlb_f("GetGraphicsMode", GetGraphicsMode),
        xlb_f("GetGValue", [](COLORREF rgb) { return GetGValue(rgb); }),
        xlb_f("GetKerningPairs", GetKerningPairs),
        xlb_f("GetLayout", GetLayout),
        xlb_f("GetMapMode", GetMapMode),
        xlb_f("GetMetaFile", GetMetaFile),
        xlb_f("GetMetaFileBitsEx", GetMetaFileBitsEx),
        xlb_f("GetMetaRgn", GetMetaRgn),
        xlb_f("GetMiterLimit", GetMiterLimit),
        xlb_f("GetMonitorInfo", GetMonitorInfo),
        xlb_f("GetNearestColor", GetNearestColor),
        xlb_f("GetNearestPaletteIndex", GetNearestPaletteIndex),
        xlb_f("GetObject", GetObject),
        xlb_f("GetObject", GetObject),
        xlb_f("GetObjectType", GetObjectType),
        xlb_f("GetOutlineTextMetrics", GetOutlineTextMetrics),
        xlb_f("GetPaletteEntries", GetPaletteEntries),
        xlb_f("GetPath", GetPath),
        xlb_f("GetPixel", GetPixel),
        xlb_f("GetPolyFillMode", GetPolyFillMode),
        xlb_f("GetRandomRgn", GetRandomRgn),
        xlb_f("GetRasterizerCaps", GetRasterizerCaps),
        xlb_f("GetRegionData", GetRegionData),
        xlb_f("GetRgnBox", GetRgnBox),
        xlb_f("GetROP2", GetROP2),
        xlb_f("GetRValue", [](COLORREF rgb) { return GetRValue(rgb); }),
        xlb_f("GetStockObject", GetStockObject),
        xlb_f("GetStretchBltMode", GetStretchBltMode),
        xlb_f("GetSysColorBrush", GetSysColorBrush),
        xlb_f("GetSystemPaletteEntries", GetSystemPaletteEntries),
        xlb_f("GetSystemPaletteUse", GetSystemPaletteUse),
        xlb_f("GetTabbedTextExtent", GetTabbedTextExtent),
        xlb_f("GetTextAlign", GetTextAlign),
        xlb_f("GetTextCharacterExtra", GetTextCharacterExtra),
        xlb_f("GetTextColor", GetTextColor),
        xlb_f("GetTextExtentExPoint", GetTextExtentExPoint),
        xlb_f("GetTextExtentExPointI", GetTextExtentExPointI),
        xlb_f("GetTextExtentPoint32A", GetTextExtentPoint32A),
        xlb_f("GetTextExtentPoint32W", GetTextExtentPoint32W),
        xlb_f("GetTextExtentPoint", GetTextExtentPoint),
        xlb_f("GetTextExtentPointI", GetTextExtentPointI),
        xlb_f("GetTextFace", GetTextFace),
        xlb_f("GetTextMetrics", GetTextMetrics),
        xlb_f("GetTextMetrics", GetTextMetrics),
        xlb_f("GetUpdateRect", GetUpdateRect),
        xlb_f("GetUpdateRgn", GetUpdateRgn),
        xlb_f("GetViewportExtEx", GetViewportExtEx),
        xlb_f("GetViewportOrgEx", GetViewportOrgEx),
        xlb_f("GetWindowDC", GetWindowDC),
        xlb_f("GetWindowExtEx", GetWindowExtEx),
        xlb_f("GetWindowOrgEx", GetWindowOrgEx),
        xlb_f("GetWindowRgn", GetWindowRgn),
        xlb_f("GetWindowRgnBox", GetWindowRgnBox),
        xlb_f("GetWinMetaFileBits", GetWinMetaFileBits),
        xlb_f("GetWorldTransform", GetWorldTransform),
        xlb_class<xlb_cbf<GOBJENUMPROC>>("GOBJENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("GradientFill", GradientFill),
        xlb_f("GrayString", GrayString),
        xlb_class<xlb_cbf<GRAYSTRINGPROC>>("GRAYSTRINGPROC").constructor<xlb_luafunc>(),
        xlb_f("InflateRect", InflateRect),
        xlb_f("IntersectClipRect", IntersectClipRect),
        xlb_f("IntersectRect", IntersectRect),
        xlb_f("InvalidateRect", InvalidateRect),
        xlb_f("InvalidateRgn", InvalidateRgn),
        xlb_f("InvertRect", InvertRect),
        xlb_f("InvertRgn", InvertRgn),
        xlb_f("IsRectEmpty", IsRectEmpty),
        xlb_f("LineDDA", LineDDA),
        xlb_class<xlb_cbf<LINEDDAPROC>>("LINEDDAPROC").constructor<xlb_luafunc>(),
        xlb_f("LineTo", LineTo),
        xlb_f("LoadBitmap", LoadBitmap),
        xlb_f("LockWindowUpdate", LockWindowUpdate),
        xlb_f("LPtoDP", LPtoDP),
        xlb_f("MAKEPOINTS", [](long l) { return MAKEPOINTS(l); }),
        xlb_f("MAKEROP4", [](uint32_t fore, uint32_t back) { return MAKEROP4(fore, back); }),
        xlb_f("MapWindowPoints", MapWindowPoints),
        xlb_f("MaskBlt", MaskBlt),
        xlb_f("MergeFontPackage", MergeFontPackage),
        xlb_class<xlb_cbf<MFENUMPROC>>("MFENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("ModifyWorldTransform", ModifyWorldTransform),
        xlb_class<xlb_cbf<MONITORENUMPROC>>("MONITORENUMPROC").constructor<xlb_luafunc>(),
        xlb_f("MonitorFromPoint", MonitorFromPoint),
        xlb_f("MonitorFromRect", MonitorFromRect),
        xlb_f("MonitorFromWindow", MonitorFromWindow),
        xlb_f("MoveToEx", MoveToEx),
        xlb_f("OffsetClipRgn", OffsetClipRgn),
        xlb_f("OffsetRect", OffsetRect),
        xlb_f("OffsetRgn", OffsetRgn),
        xlb_f("OffsetViewportOrgEx", OffsetViewportOrgEx),
        xlb_f("OffsetWindowOrgEx", OffsetWindowOrgEx),
        xlb_f("PaintDesktop", PaintDesktop),
        xlb_f("PaintRgn", PaintRgn),
        xlb_f("PALETTEINDEX", [](int i) { return PALETTEINDEX(i); }),
        xlb_f("PALETTERGB", [](int r, int g, int b) { return PALETTERGB(r,g,b); }),
        xlb_f("PatBlt", PatBlt),
        xlb_f("PathToRegion", PathToRegion),
        xlb_f("Pie", Pie),
        xlb_f("PlayEnhMetaFile", PlayEnhMetaFile),
        xlb_f("PlayEnhMetaFileRecord", PlayEnhMetaFileRecord),
        xlb_f("PlayMetaFile", PlayMetaFile),
        xlb_f("PlayMetaFileRecord", PlayMetaFileRecord),
        xlb_f("PlgBlt", PlgBlt),
        xlb_f("POINTSTOPOINT", [](POINT& pt, POINTS pts) { POINTSTOPOINT(pt,pts); }),
        xlb_f("POINTTOPOINTS", [](POINT& pt) { return POINTTOPOINTS(pt); }),
        xlb_f("PolyBezier", PolyBezier),
        xlb_f("PolyBezierTo", PolyBezierTo),
        xlb_f("PolyDraw", PolyDraw),
        xlb_f("Polygon", Polygon),
        xlb_f("Polyline", Polyline),
        xlb_f("PolylineTo", PolylineTo),
        xlb_f("PolyPolygon", PolyPolygon),
        xlb_f("PolyPolyline", PolyPolyline),
        xlb_f("PolyTextOut", PolyTextOut),
        xlb_f("PtInRect", PtInRect),
        xlb_f("PtInRegion", PtInRegion),
        xlb_f("PtVisible", PtVisible),
        xlb_f("RealizePalette", RealizePalette),
        xlb_f("Rectangle", Rectangle),
        xlb_f("RectInRegion", RectInRegion),
        xlb_f("RectVisible", RectVisible),
        xlb_f("RedrawWindow", RedrawWindow),
        xlb_f("ReleaseDC", ReleaseDC),
        xlb_f("RemoveFontMemResourceEx", RemoveFontMemResourceEx),
        xlb_f("RemoveFontResource", RemoveFontResource),
        xlb_f("RemoveFontResourceEx", RemoveFontResourceEx),
        xlb_f("ResetDCA", ResetDCA),
        xlb_f("ResetDCW", ResetDCW),
        xlb_f("ResizePalette", ResizePalette),
        xlb_f("RestoreDC", RestoreDC),
        xlb_f("RGB", [](int r, int g, int b) { return RGB(r,g,b); }),
        xlb_f("RoundRect", RoundRect),
        xlb_f("SaveDC", SaveDC),
        xlb_f("ScaleViewportExtEx", ScaleViewportExtEx),
        xlb_f("ScaleWindowExtEx", ScaleWindowExtEx),
        xlb_f("ScreenToClient", ScreenToClient),
        xlb_f("SelectClipPath", SelectClipPath),
        xlb_f("SelectClipRgn", SelectClipRgn),
        xlb_f("SelectFont", [](HDC hdc, HFONT hfont) { return SelectFont(hdc, hfont); }),
        xlb_f("SelectObject", SelectObject),
        xlb_f("SelectPalette", SelectPalette),
        xlb_f("SetArcDirection", SetArcDirection),
        xlb_f("SetBitmapBits", SetBitmapBits),
        xlb_f("SetBitmapDimensionEx", SetBitmapDimensionEx),
        xlb_f("SetBkColor", SetBkColor),
        xlb_f("SetBkMode", SetBkMode),
        xlb_f("SetBoundsRect", SetBoundsRect),
        xlb_f("SetBrushOrgEx", SetBrushOrgEx),
        xlb_f("SetColorAdjustment", SetColorAdjustment),
        xlb_f("SetDCBrushColor", SetDCBrushColor),
        xlb_f("SetDCPenColor", SetDCPenColor),
        xlb_f("SetDIBColorTable", SetDIBColorTable),
        xlb_f("SetDIBits", SetDIBits),
        xlb_f("SetDIBitsToDevice", SetDIBitsToDevice),
        xlb_f("SetEnhMetaFileBits", SetEnhMetaFileBits),
        xlb_f("SetGraphicsMode", SetGraphicsMode),
        xlb_f("SetLayout", SetLayout),
        xlb_f("SetMapMode", SetMapMode),
        xlb_f("SetMapperFlags", SetMapperFlags),
        xlb_f("SetMetaFileBitsEx", SetMetaFileBitsEx),
        xlb_f("SetMetaRgn", SetMetaRgn),
        xlb_f("SetMiterLimit", SetMiterLimit),
        xlb_f("SetPaletteEntries", SetPaletteEntries),
        xlb_f("SetPixel", SetPixel),
        xlb_f("SetPixelV", SetPixelV),
        xlb_f("SetPolyFillMode", SetPolyFillMode),
        xlb_f("SetRect", SetRect),
        xlb_f("SetRectEmpty", SetRectEmpty),
        xlb_f("SetRectRgn", SetRectRgn),
        xlb_f("SetROP2", SetROP2),
        xlb_f("SetStretchBltMode", SetStretchBltMode),
        xlb_f("SetSystemPaletteUse", SetSystemPaletteUse),
        xlb_f("SetTextAlign", SetTextAlign),
        xlb_f("SetTextCharacterExtra", SetTextCharacterExtra),
        xlb_f("SetTextColor", SetTextColor),
        xlb_f("SetTextJustification", SetTextJustification),
        xlb_f("SetViewportExtEx", SetViewportExtEx),
        xlb_f("SetViewportOrgEx", SetViewportOrgEx),
        xlb_f("SetWindowExtEx", SetWindowExtEx),
        xlb_f("SetWindowOrgEx", SetWindowOrgEx),
        xlb_f("SetWindowRgn", SetWindowRgn),
        xlb_f("SetWinMetaFileBits", SetWinMetaFileBits),
        xlb_f("SetWorldTransform", SetWorldTransform),
        xlb_f("StretchBlt", StretchBlt),
        xlb_f("StretchDIBits", StretchDIBits),
        xlb_f("StrokeAndFillPath", StrokeAndFillPath),
        xlb_f("StrokePath", StrokePath),
        xlb_f("SubtractRect", SubtractRect),
        xlb_f("TabbedTextOut", TabbedTextOut),
        xlb_f("TextOut", TextOut),
        xlb_f("TransparentBlt", TransparentBlt),
        xlb_f("TTCharToUnicode", TTCharToUnicode),
        xlb_f("TTDeleteEmbeddedFont", TTDeleteEmbeddedFont),
        xlb_f("TTEmbedFont", TTEmbedFont),
        xlb_f("TTEmbedFontEx", TTEmbedFontEx),
        xlb_f("TTEmbedFontFromFileA", TTEmbedFontFromFileA),
        xlb_f("TTEnableEmbeddingForFacename", TTEnableEmbeddingForFacename),
        xlb_f("TTGetEmbeddedFontInfo", TTGetEmbeddedFontInfo),
        xlb_f("TTGetEmbeddingType", TTGetEmbeddingType),
        xlb_f("TTGetNewFontName", TTGetNewFontName),
        xlb_f("TTIsEmbeddingEnabled", TTIsEmbeddingEnabled),
        xlb_f("TTIsEmbeddingEnabledForFacename", TTIsEmbeddingEnabledForFacename),
        xlb_f("TTLoadEmbeddedFont", TTLoadEmbeddedFont),
        xlb_f("TTRunValidationTests", TTRunValidationTests),
        xlb_f("TTRunValidationTestsEx", TTRunValidationTestsEx),
        xlb_f("UnionRect", UnionRect),
        xlb_f("UnrealizeObject", UnrealizeObject),
        xlb_f("UpdateColors", UpdateColors),
        xlb_f("UpdateWindow", UpdateWindow),
        xlb_f("ValidateRect", ValidateRect),
        xlb_f("ValidateRgn", ValidateRgn),
        xlb_f("WidenPath", WidenPath),
        xlb_f("WindowFromDC", WindowFromDC),
#ifdef compile
#endif
        xlb_class<ABC>("ABC") .constructor() .destructor()
            .property("abcA", &ABC::abcA)
            .property("abcB", &ABC::abcB)
            .property("abcC", &ABC::abcC)
            ,
        xlb_class<ABCFLOAT>("ABCFLOAT") .constructor() .destructor()
            .property("abcfA", &ABCFLOAT::abcfA)
            .property("abcfB", &ABCFLOAT::abcfB)
            .property("abcfC", &ABCFLOAT::abcfC)
            ,
        xlb_class<AXESLIST>("AXESLIST") .constructor() .destructor()
            .property("axlReserved", &AXESLIST::axlReserved)
            .property("axlNumAxes", &AXESLIST::axlNumAxes)
            .property("axlAxisInfo", &AXESLIST::axlAxisInfo)
            ,
        xlb_class<AXISINFO>("AXISINFO") .constructor() .destructor()
            .property("axMinValue", &AXISINFO::axMinValue)
            .property("axMaxValue", &AXISINFO::axMaxValue)
            .property("axAxisName", &AXISINFO::axAxisName)
            ,
        xlb_class<BITMAP>("BITMAP") .constructor() .destructor()
            .property("bmType", &BITMAP::bmType)
            .property("bmWidth", &BITMAP::bmWidth)
            .property("bmHeight", &BITMAP::bmHeight)
            .property("bmWidthBytes", &BITMAP::bmWidthBytes)
            .property("bmPlanes", &BITMAP::bmPlanes)
            .property("bmBitsPixel", &BITMAP::bmBitsPixel)
            .property("bmBits", &BITMAP::bmBits)
            , 
        xlb_class<BITMAPCOREHEADER>("BITMAPCOREHEADER") .constructor() .destructor()
            .property("bcSize", &BITMAPCOREHEADER::bcSize)
            .property("bcWidth", &BITMAPCOREHEADER::bcWidth)
            .property("bcHeight", &BITMAPCOREHEADER::bcHeight)
            .property("bcPlanes", &BITMAPCOREHEADER::bcPlanes)
            .property("bcBitCount", &BITMAPCOREHEADER::bcBitCount)
            , 
        xlb_class<BITMAPCOREINFO>("BITMAPCOREINFO") .constructor() .destructor()
            .property("bmciHeader", &BITMAPCOREINFO::bmciHeader)
            .property("bmciColors", &BITMAPCOREINFO::bmciColors)
            ,
        xlb_class<BITMAPFILEHEADER>("BITMAPFILEHEADER") .constructor() .destructor()
            .property("bfType", &BITMAPFILEHEADER::bfType)
            .property("bfSize", &BITMAPFILEHEADER::bfSize)
            .property("bfReserved1", &BITMAPFILEHEADER::bfReserved1)
            .property("bfReserved2", &BITMAPFILEHEADER::bfReserved2)
            .property("bfOffBits", &BITMAPFILEHEADER::bfOffBits)
            ,
        xlb_class<BITMAPINFO>("BITMAPINFO") .constructor() .destructor()
            .property("bmiHeader", &BITMAPINFO::bmiHeader)
            .property("bmiColors", &BITMAPINFO::bmiColors)
            ,
        xlb_class<BITMAPV4HEADER>("BITMAPV4HEADER") .constructor() .destructor()
            .property("bV4Size", &BITMAPV4HEADER::bV4Size)
            .property("bV4Width", &BITMAPV4HEADER::bV4Width)
            .property("bV4Height", &BITMAPV4HEADER::bV4Height)
            .property("bV4Planes", &BITMAPV4HEADER::bV4Planes)
            .property("bV4BitCount", &BITMAPV4HEADER::bV4BitCount)
            .property("bV4V4Compression", &BITMAPV4HEADER::bV4V4Compression)
            .property("bV4SizeImage", &BITMAPV4HEADER::bV4SizeImage)
            .property("bV4XPelsPerMeter", &BITMAPV4HEADER::bV4XPelsPerMeter)
            .property("bV4YPelsPerMeter", &BITMAPV4HEADER::bV4YPelsPerMeter)
            .property("bV4ClrUsed", &BITMAPV4HEADER::bV4ClrUsed)
            .property("bV4ClrImportant", &BITMAPV4HEADER::bV4ClrImportant)
            .property("bV4RedMask", &BITMAPV4HEADER::bV4RedMask)
            .property("bV4GreenMask", &BITMAPV4HEADER::bV4GreenMask)
            .property("bV4BlueMask", &BITMAPV4HEADER::bV4BlueMask)
            .property("bV4AlphaMask", &BITMAPV4HEADER::bV4AlphaMask)
            .property("bV4CSType", &BITMAPV4HEADER::bV4CSType)
            .property("bV4Endpoints", &BITMAPV4HEADER::bV4Endpoints)
            .property("bV4GammaRed", &BITMAPV4HEADER::bV4GammaRed)
            .property("bV4GammaGreen", &BITMAPV4HEADER::bV4GammaGreen)
            .property("bV4GammaBlue", &BITMAPV4HEADER::bV4GammaBlue)
            ,
        xlb_class<BITMAPV5HEADER>("BITMAPV5HEADER") .constructor() .destructor()
            .property("bV5Size", &BITMAPV5HEADER::bV5Size)
            .property("bV5Width", &BITMAPV5HEADER::bV5Width)
            .property("bV5Height", &BITMAPV5HEADER::bV5Height)
            .property("bV5Planes", &BITMAPV5HEADER::bV5Planes)
            .property("bV5BitCount", &BITMAPV5HEADER::bV5BitCount)
            .property("bV5Compression", &BITMAPV5HEADER::bV5Compression)
            .property("bV5SizeImage", &BITMAPV5HEADER::bV5SizeImage)
            .property("bV5XPelsPerMeter", &BITMAPV5HEADER::bV5XPelsPerMeter)
            .property("bV5YPelsPerMeter", &BITMAPV5HEADER::bV5YPelsPerMeter)
            .property("bV5ClrUsed", &BITMAPV5HEADER::bV5ClrUsed)
            .property("bV5ClrImportant", &BITMAPV5HEADER::bV5ClrImportant)
            .property("bV5RedMask", &BITMAPV5HEADER::bV5RedMask)
            .property("bV5GreenMask", &BITMAPV5HEADER::bV5GreenMask)
            .property("bV5BlueMask", &BITMAPV5HEADER::bV5BlueMask)
            .property("bV5AlphaMask", &BITMAPV5HEADER::bV5AlphaMask)
            .property("bV5CSType", &BITMAPV5HEADER::bV5CSType)
            .property("bV5Endpoints", &BITMAPV5HEADER::bV5Endpoints)
            .property("bV5GammaRed", &BITMAPV5HEADER::bV5GammaRed)
            .property("bV5GammaGreen", &BITMAPV5HEADER::bV5GammaGreen)
            .property("bV5GammaBlue", &BITMAPV5HEADER::bV5GammaBlue)
            .property("bV5Intent", &BITMAPV5HEADER::bV5Intent)
            .property("bV5ProfileData", &BITMAPV5HEADER::bV5ProfileData)
            .property("bV5ProfileSize", &BITMAPV5HEADER::bV5ProfileSize)
            .property("bV5Reserved", &BITMAPV5HEADER::bV5Reserved)
            ,
        xlb_class<BLENDFUNCTION>("BLENDFUNCTION") .constructor() .destructor()
            .property("BlendOp", &BLENDFUNCTION::BlendOp)
            .property("BlendFlags", &BLENDFUNCTION::BlendFlags)
            .property("SourceConstantAlpha", &BLENDFUNCTION::SourceConstantAlpha)
            .property("AlphaFormat", &BLENDFUNCTION::AlphaFormat)
            ,
        xlb_class<COLORADJUSTMENT>("COLORADJUSTMENT") .constructor() .destructor()
            .property("caSize", &COLORADJUSTMENT::caSize)
            .property("caFlags", &COLORADJUSTMENT::caFlags)
            .property("caIlluminantIndex", &COLORADJUSTMENT::caIlluminantIndex)
            .property("caRedGamma", &COLORADJUSTMENT::caRedGamma)
            .property("caGreenGamma", &COLORADJUSTMENT::caGreenGamma)
            .property("caBlueGamma", &COLORADJUSTMENT::caBlueGamma)
            .property("caReferenceBlack", &COLORADJUSTMENT::caReferenceBlack)
            .property("caReferenceWhite", &COLORADJUSTMENT::caReferenceWhite)
            .property("caContrast", &COLORADJUSTMENT::caContrast)
            .property("caBrightness", &COLORADJUSTMENT::caBrightness)
            .property("caColorfulness", &COLORADJUSTMENT::caColorfulness)
            .property("caRedGreenTint", &COLORADJUSTMENT::caRedGreenTint)
            ,
        xlb_class<DESIGNVECTOR>("DESIGNVECTOR") .constructor() .destructor()
            .property("dvReserved", &DESIGNVECTOR::dvReserved)
            .property("dvNumAxes", &DESIGNVECTOR::dvNumAxes)
            .property("dvValues", &DESIGNVECTOR::dvValues)
            ,
        xlb_class<DIBSECTION>("DIBSECTION") .constructor() .destructor()
            .property("dsBm", &DIBSECTION::dsBm)
            .property("dsBmih", &DIBSECTION::dsBmih)
            .property("dsBitfields", &DIBSECTION::dsBitfields)
            .property("dshSection", &DIBSECTION::dshSection)
            .property("dsOffset", &DIBSECTION::dsOffset)
            ,
        xlb_class<DISPLAY_DEVICE>("DISPLAY_DEVICE") .constructor() .destructor()
            .property("cb", &DISPLAY_DEVICE::cb)
            .property("DeviceName", &DISPLAY_DEVICE::DeviceName)
            .property("DeviceString", &DISPLAY_DEVICE::DeviceString)
            .property("StateFlags", &DISPLAY_DEVICE::StateFlags)
            .property("DeviceID", &DISPLAY_DEVICE::DeviceID)
            .property("DeviceKey", &DISPLAY_DEVICE::DeviceKey)
            ,
        xlb_class<DRAWTEXTPARAMS>("DRAWTEXTPARAMS") .constructor() .destructor()
            .property("cbSize", &DRAWTEXTPARAMS::cbSize)
            .property("iTabLength", &DRAWTEXTPARAMS::iTabLength)
            .property("iLeftMargin", &DRAWTEXTPARAMS::iLeftMargin)
            .property("iRightMargin", &DRAWTEXTPARAMS::iRightMargin)
            .property("uiLengthDrawn", &DRAWTEXTPARAMS::uiLengthDrawn)
            ,
        xlb_class<EMR>("EMR") .constructor() .destructor()
            .property("iType", &EMR::iType)
            .property("nSize", &EMR::nSize)
            ,
        xlb_class<EMRABORTPATH>("EMRABORTPATH") .constructor() .destructor()
            .property("emr", &EMRABORTPATH::emr)
            ,
        xlb_class<EMRALPHABLEND>("EMRALPHABLEND") .constructor() .destructor()
            .property("emr", &EMRALPHABLEND::emr)
            .property("rclBounds", &EMRALPHABLEND::rclBounds)
            .property("xDest", &EMRALPHABLEND::xDest)
            .property("yDest", &EMRALPHABLEND::yDest)
            .property("cxDest", &EMRALPHABLEND::cxDest)
            .property("cyDest", &EMRALPHABLEND::cyDest)
            .property("dwRop", &EMRALPHABLEND::dwRop)
            .property("xSrc", &EMRALPHABLEND::xSrc)
            .property("ySrc", &EMRALPHABLEND::ySrc)
            .property("xformSrc", &EMRALPHABLEND::xformSrc)
            .property("crBkColorSrc", &EMRALPHABLEND::crBkColorSrc)
            .property("iUsageSrc", &EMRALPHABLEND::iUsageSrc)
            .property("offBmiSrc", &EMRALPHABLEND::offBmiSrc)
            .property("cbBmiSrc", &EMRALPHABLEND::cbBmiSrc)
            .property("offBitsSrc", &EMRALPHABLEND::offBitsSrc)
            .property("cbBitsSrc", &EMRALPHABLEND::cbBitsSrc)
            .property("cxSrc", &EMRALPHABLEND::cxSrc)
            .property("cySrc", &EMRALPHABLEND::cySrc)
            ,
        xlb_class<EMRANGLEARC>("EMRANGLEARC") .constructor() .destructor()
            .property("emr", &EMRANGLEARC::emr)
            .property("ptlCenter", &EMRANGLEARC::ptlCenter)
            .property("nRadius", &EMRANGLEARC::nRadius)
            .property("eStartAngle", &EMRANGLEARC::eStartAngle)
            .property("eSweepAngle", &EMRANGLEARC::eSweepAngle)
            ,
        xlb_class<EMRARC>("EMRARC") .constructor() .destructor()
            .property("emr", &EMRARC::emr)
            .property("rclBox", &EMRARC::rclBox)
            .property("ptlStart", &EMRARC::ptlStart)
            .property("ptlEnd", &EMRARC::ptlEnd)
            ,
        xlb_class<EMRBITBLT>("EMRARCEMRBITBLT") .constructor() .destructor()
            .property("emr", &EMRBITBLT::emr)
            .property("rclBounds", &EMRBITBLT::rclBounds)
            .property("xDest", &EMRBITBLT::xDest)
            .property("yDest", &EMRBITBLT::yDest)
            .property("cxDest", &EMRBITBLT::cxDest)
            .property("cyDest", &EMRBITBLT::cyDest)
            .property("dwRop", &EMRBITBLT::dwRop)
            .property("xSrc", &EMRBITBLT::xSrc)
            .property("ySrc", &EMRBITBLT::ySrc)
            .property("xformSrc", &EMRBITBLT::xformSrc)
            .property("crBkColorSrc", &EMRBITBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRBITBLT::iUsageSrc)
            .property("offBmiSrc", &EMRBITBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRBITBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRBITBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRBITBLT::cbBitsSrc)
            ,
        xlb_class<EMRCOLORCORRECTPALETTE>("EMRCOLORCORRECTPALETTE") .constructor() .destructor()
            .property("emr", &EMRCOLORCORRECTPALETTE::emr)
            .property("ihPalette", &EMRCOLORCORRECTPALETTE::ihPalette)
            .property("nFirstEntry", &EMRCOLORCORRECTPALETTE::nFirstEntry)
            .property("nPalEntries", &EMRCOLORCORRECTPALETTE::nPalEntries)
            .property("nReserved", &EMRCOLORCORRECTPALETTE::nReserved)
            ,
        xlb_class<EMRCOLORMATCHTOTARGET>("EMRCOLORMATCHTOTARGET") .constructor() .destructor()
            .property("emr", &EMRCOLORMATCHTOTARGET::emr)
            .property("dwAction", &EMRCOLORMATCHTOTARGET::dwAction)
            .property("dwFlags", &EMRCOLORMATCHTOTARGET::dwFlags)
            .property("cbName", &EMRCOLORMATCHTOTARGET::cbName)
            .property("cbData", &EMRCOLORMATCHTOTARGET::cbData)
            .property("Data", &EMRCOLORMATCHTOTARGET::Data)
            ,
        xlb_class<EMRCREATEBRUSHINDIRECT>("EMRCREATEBRUSHINDIRECT") .constructor() .destructor()
            .property("emr", &EMRCREATEBRUSHINDIRECT::emr)
            .property("ihBrush", &EMRCREATEBRUSHINDIRECT::ihBrush)
            .property("lb", &EMRCREATEBRUSHINDIRECT::lb)
            ,
        xlb_class<EMRCREATECOLORSPACE>("EMRCREATECOLORSPACE") .constructor() .destructor()
            .property("emr", &EMRCREATECOLORSPACE::emr)
            .property("ihCS", &EMRCREATECOLORSPACE::ihCS)
            .property("lcs", &EMRCREATECOLORSPACE::lcs)
            ,
        xlb_class<EMRCREATECOLORSPACEW>("EMRCREATECOLORSPACEW") .constructor() .destructor()
            .property("emr", &EMRCREATECOLORSPACEW::emr)
            .property("ihCS", &EMRCREATECOLORSPACEW::ihCS)
            .property("lcs", &EMRCREATECOLORSPACEW::lcs)
            .property("dwFlags", &EMRCREATECOLORSPACEW::dwFlags)
            .property("cbData", &EMRCREATECOLORSPACEW::cbData)
            .property("Data", &EMRCREATECOLORSPACEW::Data)
            ,
        xlb_class<EMRCREATEDIBPATTERNBRUSHPT>("EMRCREATEDIBPATTERNBRUSHPT") .constructor() .destructor()
            .property("emr", &EMRCREATEDIBPATTERNBRUSHPT::emr)
            .property("ihBrush", &EMRCREATEDIBPATTERNBRUSHPT::ihBrush)
            .property("iUsage", &EMRCREATEDIBPATTERNBRUSHPT::iUsage)
            .property("offBmi", &EMRCREATEDIBPATTERNBRUSHPT::offBmi)
            .property("cbBmi", &EMRCREATEDIBPATTERNBRUSHPT::cbBmi)
            .property("offBits", &EMRCREATEDIBPATTERNBRUSHPT::offBits)
            .property("cbBits", &EMRCREATEDIBPATTERNBRUSHPT::cbBits)
            ,
        xlb_class<EMRCREATEMONOBRUSH>("EMRCREATEMONOBRUSH") .constructor() .destructor()
            .property("emr", &EMRCREATEMONOBRUSH::emr)
            .property("ihBrush", &EMRCREATEMONOBRUSH::ihBrush)
            .property("iUsage", &EMRCREATEMONOBRUSH::iUsage)
            .property("offBmi", &EMRCREATEMONOBRUSH::offBmi)
            .property("cbBmi", &EMRCREATEMONOBRUSH::cbBmi)
            .property("offBits", &EMRCREATEMONOBRUSH::offBits)
            .property("cbBits", &EMRCREATEMONOBRUSH::cbBits)
            ,
        xlb_class<EMRCREATEPALETTE>("EMRCREATEPALETTE") .constructor() .destructor()
            .property("emr", &EMRCREATEPALETTE::emr)
            .property("ihPal", &EMRCREATEPALETTE::ihPal)
            .property("lgpl", &EMRCREATEPALETTE::lgpl)
            ,
        xlb_class<EMRCREATEPEN>("EMRCREATEPEN") .constructor() .destructor()
            .property("emr", &EMRCREATEPEN::emr)
            .property("ihPen", &EMRCREATEPEN::ihPen)
            .property("lopn", &EMRCREATEPEN::lopn)
            ,
        xlb_class<EMRELLIPSE>("EMRELLIPSE") .constructor() .destructor()
            .property("emr", &EMRELLIPSE::emr)
            .property("rclBox", &EMRELLIPSE::rclBox)
            ,
        xlb_class<EMREOF>("EMREOF") .constructor() .destructor()
            .property("emr", &EMREOF::emr)
            .property("nPalEntries", &EMREOF::nPalEntries)
            .property("offPalEntries", &EMREOF::offPalEntries)
            .property("nSizeLast", &EMREOF::nSizeLast)
            ,
        xlb_class<EMREXCLUDECLIPRECT>("EMREXCLUDECLIPRECT") .constructor() .destructor()
            .property("emr", &EMREXCLUDECLIPRECT::emr)
            .property("rclClip", &EMREXCLUDECLIPRECT::rclClip)
            ,
        xlb_class<EMREXTCREATEFONTINDIRECTW>("EMREXTCREATEFONTINDIRECTW") .constructor() .destructor()
            .property("emr", &EMREXTCREATEFONTINDIRECTW::emr)
            .property("ihFont", &EMREXTCREATEFONTINDIRECTW::ihFont)
            .property("elfw", &EMREXTCREATEFONTINDIRECTW::elfw)
            ,
        xlb_class<EMREXTCREATEPEN>("EMREXTCREATEPEN") .constructor() .destructor()
            .property("emr", &EMREXTCREATEPEN::emr)
            .property("ihPen", &EMREXTCREATEPEN::ihPen)
            .property("offBmi", &EMREXTCREATEPEN::offBmi)
            .property("cbBmi", &EMREXTCREATEPEN::cbBmi)
            .property("offBits", &EMREXTCREATEPEN::offBits)
            .property("cbBits", &EMREXTCREATEPEN::cbBits)
            .property("elp", &EMREXTCREATEPEN::elp)
            ,
        xlb_class<EMREXTFLOODFILL>("EMREXTFLOODFILL") .constructor() .destructor()
            .property("emr", &EMREXTFLOODFILL::emr)
            .property("ptlStart", &EMREXTFLOODFILL::ptlStart)
            .property("crColor", &EMREXTFLOODFILL::crColor)
            .property("iMode", &EMREXTFLOODFILL::iMode)
            ,
        xlb_class<EMREXTSELECTCLIPRGN>("EMREXTSELECTCLIPRGN") .constructor() .destructor()
            .property("emr", &EMREXTSELECTCLIPRGN::emr)
            .property("cbRgnData", &EMREXTSELECTCLIPRGN::cbRgnData)
            .property("iMode", &EMREXTSELECTCLIPRGN::iMode)
            .property("RgnData", &EMREXTSELECTCLIPRGN::RgnData)
            ,
        xlb_class<EMREXTTEXTOUTA>("EMREXTTEXTOUTA") .constructor() .destructor()
            .property("emr", &EMREXTTEXTOUTA::emr)
            .property("rclBounds", &EMREXTTEXTOUTA::rclBounds)
            .property("iGraphicsMode", &EMREXTTEXTOUTA::iGraphicsMode)
            .property("exScale", &EMREXTTEXTOUTA::exScale)
            .property("eyScale", &EMREXTTEXTOUTA::eyScale)
            .property("emrtext", &EMREXTTEXTOUTA::emrtext)
            ,
        xlb_class<EMRFILLPATH>("EMRFILLPATH") .constructor() .destructor()
            .property("emr", &EMRFILLPATH::emr)
            .property("rclBounds", &EMRFILLPATH::rclBounds)
            ,
        xlb_class<EMRFILLRGN>("EMRFILLRGN") .constructor() .destructor()
            .property("emr", &EMRFILLRGN::emr)
            .property("rclBounds", &EMRFILLRGN::rclBounds)
            .property("cbRgnData", &EMRFILLRGN::cbRgnData)
            .property("ihBrush", &EMRFILLRGN::ihBrush)
            .property("RgnData", &EMRFILLRGN::RgnData)
            ,
        xlb_class<EMRFORMAT>("EMRFORMAT") .constructor() .destructor()
            .property("dSignature", &EMRFORMAT::dSignature)
            .property("nVersion", &EMRFORMAT::nVersion)
            .property("cbData", &EMRFORMAT::cbData)
            .property("offData", &EMRFORMAT::offData)
            ,
        xlb_class<EMRFRAMERGN>("EMRFRAMERGN") .constructor() .destructor()
            .property("emr", &EMRFRAMERGN::emr)
            .property("rclBounds", &EMRFRAMERGN::rclBounds)
            .property("cbRgnData", &EMRFRAMERGN::cbRgnData)
            .property("ihBrush", &EMRFRAMERGN::ihBrush)
            .property("szlStroke", &EMRFRAMERGN::szlStroke)
            .property("RgnData", &EMRFRAMERGN::RgnData)
            ,
        xlb_class<EMRGDICOMMENT>("EMRGDICOMMENT") .constructor() .destructor()
            .property("emr", &EMRGDICOMMENT::emr)
            .property("cbData", &EMRGDICOMMENT::cbData)
            .property("Data", &EMRGDICOMMENT::Data)
            ,
        xlb_class<EMRGLSBOUNDEDRECORD>("EMRGLSBOUNDEDRECORD") .constructor() .destructor()
            .property("emr", &EMRGLSBOUNDEDRECORD::emr)
            .property("rclBounds", &EMRGLSBOUNDEDRECORD::rclBounds)
            .property("cbData", &EMRGLSBOUNDEDRECORD::cbData)
            .property("Data", &EMRGLSBOUNDEDRECORD::Data)
            ,
        xlb_class<EMRGLSRECORD>("EMRGLSRECORD") .constructor() .destructor()
            .property("emr", &EMRGLSRECORD::emr)
            .property("cbData", &EMRGLSRECORD::cbData)
            .property("Data", &EMRGLSRECORD::Data)
            ,
        xlb_class<EMRGRADIENTFILL>("EMRGRADIENTFILL") .constructor() .destructor()
            .property("emr", &EMRGRADIENTFILL::emr)
            .property("rclBounds", &EMRGRADIENTFILL::rclBounds)
            .property("nVer", &EMRGRADIENTFILL::nVer)
            .property("nTri", &EMRGRADIENTFILL::nTri)
            .property("ulMode", &EMRGRADIENTFILL::ulMode)
            .property("Ver", &EMRGRADIENTFILL::Ver)
            ,
        xlb_class<EMRINVERTRGN>("EMRINVERTRGN") .constructor() .destructor()
            .property("emr", &EMRINVERTRGN::emr)
            .property("rclBounds", &EMRINVERTRGN::rclBounds)
            .property("cbRgnData", &EMRINVERTRGN::cbRgnData)
            .property("RgnData", &EMRINVERTRGN::RgnData)
            ,
        xlb_class<EMRLINETO>("EMRLINETO") .constructor() .destructor()
            .property("emr", &EMRLINETO::emr)
            .property("ptl", &EMRLINETO::ptl)
            ,
        xlb_class<EMRMASKBLT>("EMRMASKBLT") .constructor() .destructor()
            .property("emr", &EMRMASKBLT::emr)
            .property("rclBounds", &EMRMASKBLT::rclBounds)
            .property("xDest", &EMRMASKBLT::xDest)
            .property("yDest", &EMRMASKBLT::yDest)
            .property("cxDest", &EMRMASKBLT::cxDest)
            .property("cyDest", &EMRMASKBLT::cyDest)
            .property("dwRop", &EMRMASKBLT::dwRop)
            .property("xSrc", &EMRMASKBLT::xSrc)
            .property("ySrc", &EMRMASKBLT::ySrc)
            .property("xformSrc", &EMRMASKBLT::xformSrc)
            .property("crBkColorSrc", &EMRMASKBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRMASKBLT::iUsageSrc)
            .property("offBmiSrc", &EMRMASKBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRMASKBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRMASKBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRMASKBLT::cbBitsSrc)
            .property("xMask", &EMRMASKBLT::xMask)
            .property("yMask", &EMRMASKBLT::yMask)
            .property("iUsageMask", &EMRMASKBLT::iUsageMask)
            .property("offBmiMask", &EMRMASKBLT::offBmiMask)
            .property("cbBmiMask", &EMRMASKBLT::cbBmiMask)
            .property("offBitsMask", &EMRMASKBLT::offBitsMask)
            .property("cbBitsMask", &EMRMASKBLT::cbBitsMask)
            ,
        xlb_class<EMRMODIFYWORLDTRANSFORM>("EMRMODIFYWORLDTRANSFORM") .constructor() .destructor()
            .property("emr", &EMRMODIFYWORLDTRANSFORM::emr)
            .property("xform", &EMRMODIFYWORLDTRANSFORM::xform)
            .property("iMode", &EMRMODIFYWORLDTRANSFORM::iMode)
            ,
        xlb_class<EMROFFSETCLIPRGN>("EMROFFSETCLIPRGN") .constructor() .destructor()
            .property("emr", &EMROFFSETCLIPRGN::emr)
            .property("ptlOffset", &EMROFFSETCLIPRGN::ptlOffset)
            ,
        xlb_class<EMRPIXELFORMAT>("EMRPIXELFORMAT") .constructor() .destructor()
            .property("emr", &EMRPIXELFORMAT::emr)
            .property("pfd", &EMRPIXELFORMAT::pfd)
            ,
        xlb_class<EMRPLGBLT>("EMRPLGBLT") .constructor() .destructor()
            .property("emr", &EMRPLGBLT::emr)
            .property("rclBounds", &EMRPLGBLT::rclBounds)
            .property("aptlDest", &EMRPLGBLT::aptlDest)
            .property("xSrc", &EMRPLGBLT::xSrc)
            .property("ySrc", &EMRPLGBLT::ySrc)
            .property("cxSrc", &EMRPLGBLT::cxSrc)
            .property("cySrc", &EMRPLGBLT::cySrc)
            .property("xformSrc", &EMRPLGBLT::xformSrc)
            .property("crBkColorSrc", &EMRPLGBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRPLGBLT::iUsageSrc)
            .property("offBmiSrc", &EMRPLGBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRPLGBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRPLGBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRPLGBLT::cbBitsSrc)
            .property("xMask", &EMRPLGBLT::xMask)
            .property("yMask", &EMRPLGBLT::yMask)
            .property("iUsageMask", &EMRPLGBLT::iUsageMask)
            .property("offBmiMask", &EMRPLGBLT::offBmiMask)
            .property("cbBmiMask", &EMRPLGBLT::cbBmiMask)
            .property("offBitsMask", &EMRPLGBLT::offBitsMask)
            .property("cbBitsMask", &EMRPLGBLT::cbBitsMask)
            ,
        xlb_class<EMRPOLYDRAW>("EMRPOLYDRAW") .constructor() .destructor()
            .property("emr", &EMRPOLYDRAW::emr)
            .property("rclBounds", &EMRPOLYDRAW::rclBounds)
            .property("cptl", &EMRPOLYDRAW::cptl)
            .property("aptl", &EMRPOLYDRAW::aptl)
            .property("abTypes", &EMRPOLYDRAW::abTypes)
            ,
        xlb_class<EMRPOLYDRAW16>("EMRPOLYDRAW16") .constructor() .destructor()
            .property("emr", &EMRPOLYDRAW16::emr)
            .property("rclBounds", &EMRPOLYDRAW16::rclBounds)
            .property("cpts", &EMRPOLYDRAW16::cpts)
            .property("apts", &EMRPOLYDRAW16::apts)
            .property("abTypes", &EMRPOLYDRAW16::abTypes)
            ,
        xlb_class<EMRPOLYLINE>("EMRPOLYLINE") .constructor() .destructor()
            .property("emr", &EMRPOLYLINE::emr)
            .property("rclBounds", &EMRPOLYLINE::rclBounds)
            .property("cptl", &EMRPOLYLINE::cptl)
            .property("aptl", &EMRPOLYLINE::aptl)
            ,
        xlb_class<EMRPOLYLINE16>("EMRPOLYLINE16") .constructor() .destructor()
            .property("emr", &EMRPOLYLINE16::emr)
            .property("rclBounds", &EMRPOLYLINE16::rclBounds)
            .property("cpts", &EMRPOLYLINE16::cpts)
            .property("apts", &EMRPOLYLINE16::apts)
            ,
        xlb_class<EMRPOLYPOLYLINE>("EMRPOLYPOLYLINE") .constructor() .destructor()
            .property("emr", &EMRPOLYPOLYLINE::emr)
            .property("rclBounds", &EMRPOLYPOLYLINE::rclBounds)
            .property("nPolys", &EMRPOLYPOLYLINE::nPolys)
            .property("cptl", &EMRPOLYPOLYLINE::cptl)
            .property("aPolyCounts", &EMRPOLYPOLYLINE::aPolyCounts)
            .property("aptl", &EMRPOLYPOLYLINE::aptl)
            ,
        xlb_class<EMRPOLYPOLYLINE16>("EMRPOLYPOLYLINE16") .constructor() .destructor()
            .property("emr", &EMRPOLYPOLYLINE16::emr)
            .property("rclBounds", &EMRPOLYPOLYLINE16::rclBounds)
            .property("nPolys", &EMRPOLYPOLYLINE16::nPolys)
            .property("cpts", &EMRPOLYPOLYLINE16::cpts)
            .property("aPolyCounts", &EMRPOLYPOLYLINE16::aPolyCounts)
            .property("apts", &EMRPOLYPOLYLINE16::apts)
            ,
        xlb_class<EMRPOLYTEXTOUTA>("EMRPOLYTEXTOUTA") .constructor() .destructor()
            .property("emr", &EMRPOLYTEXTOUTA::emr)
            .property("rclBounds", &EMRPOLYTEXTOUTA::rclBounds)
            .property("iGraphicsMode", &EMRPOLYTEXTOUTA::iGraphicsMode)
            .property("exScale", &EMRPOLYTEXTOUTA::exScale)
            .property("eyScale", &EMRPOLYTEXTOUTA::eyScale)
            .property("cStrings", &EMRPOLYTEXTOUTA::cStrings)
            .property("aemrtext", &EMRPOLYTEXTOUTA::aemrtext)
            ,
        xlb_class<EMRRESIZEPALETTE>("EMRRESIZEPALETTE") .constructor() .destructor()
            .property("emr", &EMRRESIZEPALETTE::emr)
            .property("ihPal", &EMRRESIZEPALETTE::ihPal)
            .property("cEntries", &EMRRESIZEPALETTE::cEntries)
            ,
        xlb_class<EMRRESTOREDC>("EMRRESTOREDC") .constructor() .destructor()
            .property("emr", &EMRRESTOREDC::emr)
            .property("iRelative", &EMRRESTOREDC::iRelative)
            ,
        xlb_class<EMRROUNDRECT>("EMRROUNDRECT") .constructor() .destructor()
            .property("emr", &EMRROUNDRECT::emr)
            .property("rclBox", &EMRROUNDRECT::rclBox)
            .property("szlCorner", &EMRROUNDRECT::szlCorner)
            ,
        xlb_class<EMRSCALEVIEWPORTEXTEX>("EMRSCALEVIEWPORTEXTEX") .constructor() .destructor()
            .property("emr", &EMRSCALEVIEWPORTEXTEX::emr)
            .property("xNum", &EMRSCALEVIEWPORTEXTEX::xNum)
            .property("xDenom", &EMRSCALEVIEWPORTEXTEX::xDenom)
            .property("yNum", &EMRSCALEVIEWPORTEXTEX::yNum)
            .property("yDenom", &EMRSCALEVIEWPORTEXTEX::yDenom)
            ,
        xlb_class<EMRSELECTCLIPPATH>("EMRSELECTCLIPPATH") .constructor() .destructor()
            .property("emr", &EMRSELECTCLIPPATH::emr)
            .property("iMode", &EMRSELECTCLIPPATH::iMode)
            ,
        xlb_class<EMRSELECTOBJECT>("EMRSELECTOBJECT") .constructor() .destructor()
            .property("emr", &EMRSELECTOBJECT::emr)
            .property("ihObject", &EMRSELECTOBJECT::ihObject)
            ,
        xlb_class<EMRSELECTPALETTE>("EMRSELECTPALETTE") .constructor() .destructor()
            .property("emr", &EMRSELECTPALETTE::emr)
            .property("ihPal", &EMRSELECTPALETTE::ihPal)
            ,
        xlb_class<EMRSETARCDIRECTION>("EMRSETARCDIRECTION") .constructor() .destructor()
            .property("emr", &EMRSETARCDIRECTION::emr)
            .property("iArcDirection", &EMRSETARCDIRECTION::iArcDirection)
            ,
        xlb_class<EMRSETBKCOLOR>("EMRSETBKCOLOR") .constructor() .destructor()
            .property("emr", &EMRSETBKCOLOR::emr)
            .property("crColor", &EMRSETBKCOLOR::crColor)
            ,
        xlb_class<EMRSETCOLORADJUSTMENT>("EMRSETCOLORADJUSTMENT") .constructor() .destructor()
            .property("emr", &EMRSETCOLORADJUSTMENT::emr)
            .property("ColorAdjustment", &EMRSETCOLORADJUSTMENT::ColorAdjustment)
            ,
        xlb_class<EMRSETCOLORSPACE>("EMRSETCOLORSPACE") .constructor() .destructor()
            .property("emr", &EMRSETCOLORSPACE::emr)
            .property("ihCS", &EMRSETCOLORSPACE::ihCS)
            ,
        xlb_class<EMRSETDIBITSTODEVICE>("EMRSETDIBITSTODEVICE") .constructor() .destructor()
            .property("emr", &EMRSETDIBITSTODEVICE::emr)
            .property("rclBounds", &EMRSETDIBITSTODEVICE::rclBounds)
            .property("xDest", &EMRSETDIBITSTODEVICE::xDest)
            .property("yDest", &EMRSETDIBITSTODEVICE::yDest)
            .property("xSrc", &EMRSETDIBITSTODEVICE::xSrc)
            .property("ySrc", &EMRSETDIBITSTODEVICE::ySrc)
            .property("cxSrc", &EMRSETDIBITSTODEVICE::cxSrc)
            .property("cySrc", &EMRSETDIBITSTODEVICE::cySrc)
            .property("offBmiSrc", &EMRSETDIBITSTODEVICE::offBmiSrc)
            .property("cbBmiSrc", &EMRSETDIBITSTODEVICE::cbBmiSrc)
            .property("offBitsSrc", &EMRSETDIBITSTODEVICE::offBitsSrc)
            .property("cbBitsSrc", &EMRSETDIBITSTODEVICE::cbBitsSrc)
            .property("iUsageSrc", &EMRSETDIBITSTODEVICE::iUsageSrc)
            .property("iStartScan", &EMRSETDIBITSTODEVICE::iStartScan)
            .property("cScans", &EMRSETDIBITSTODEVICE::cScans)
            ,
        xlb_class<EMRSETICMPROFILE>("EMRSETICMPROFILE") .constructor() .destructor()
            .property("emr", &EMRSETICMPROFILE::emr)
            .property("dwFlags", &EMRSETICMPROFILE::dwFlags)
            .property("cbName", &EMRSETICMPROFILE::cbName)
            .property("cbData", &EMRSETICMPROFILE::cbData)
            .property("Data", &EMRSETICMPROFILE::Data)
            ,
        xlb_class<EMRSETMAPPERFLAGS>("EMRSETMAPPERFLAGS") .constructor() .destructor()
            .property("emr", &EMRSETICMPROFILE::emr)
            .property("dwFlags", &EMRSETICMPROFILE::dwFlags)
            ,
        xlb_class<EMRSETMITERLIMIT>("EMRSETMITERLIMIT") .constructor() .destructor()
            .property("emr", &EMRSETMITERLIMIT::emr)
            .property("eMiterLimit", &EMRSETMITERLIMIT::eMiterLimit)
            ,
        xlb_class<EMRSETPALETTEENTRIES>("EMRSETPALETTEENTRIES") .constructor() .destructor()
            .property("emr", &EMRSETPALETTEENTRIES::emr)
            .property("ihPal", &EMRSETPALETTEENTRIES::ihPal)
            .property("iStart", &EMRSETPALETTEENTRIES::iStart)
            .property("cEntries", &EMRSETPALETTEENTRIES::cEntries)
            .property("aPalEntries", &EMRSETPALETTEENTRIES::aPalEntries)
            ,
        xlb_class<EMRSETPIXELV>("EMRSETPIXELV") .constructor() .destructor()
            .property("emr", &EMRSETPIXELV::emr)
            .property("ptlPixel", &EMRSETPIXELV::ptlPixel)
            .property("crColor", &EMRSETPIXELV::crColor)
            ,
        xlb_class<EMRSETVIEWPORTEXTEX>("EMRSETVIEWPORTEXTEX") .constructor() .destructor()
            .property("emr", &EMRSETVIEWPORTEXTEX::emr)
            .property("szlExtent", &EMRSETVIEWPORTEXTEX::szlExtent)
            ,
        xlb_class<EMRSETVIEWPORTORGEX>("EMRSETVIEWPORTORGEX") .constructor() .destructor()
            .property("emr", &EMRSETVIEWPORTORGEX::emr)
            .property("ptlOrigin", &EMRSETVIEWPORTORGEX::ptlOrigin)
            ,
        xlb_class<EMRSETWORLDTRANSFORM>("EMRSETWORLDTRANSFORM") .constructor() .destructor()
            .property("emr", &EMRSETWORLDTRANSFORM::emr)
            .property("xform", &EMRSETWORLDTRANSFORM::xform)
            ,
        xlb_class<EMRSTRETCHBLT>("EMRSTRETCHBLT") .constructor() .destructor()
            .property("emr", &EMRSTRETCHBLT::emr)
            .property("rclBounds", &EMRSTRETCHBLT::rclBounds)
            .property("xDest", &EMRSTRETCHBLT::xDest)
            .property("yDest", &EMRSTRETCHBLT::yDest)
            .property("cxDest", &EMRSTRETCHBLT::cxDest)
            .property("cyDest", &EMRSTRETCHBLT::cyDest)
            .property("dwRop", &EMRSTRETCHBLT::dwRop)
            .property("xSrc", &EMRSTRETCHBLT::xSrc)
            .property("ySrc", &EMRSTRETCHBLT::ySrc)
            .property("xformSrc", &EMRSTRETCHBLT::xformSrc)
            .property("crBkColorSrc", &EMRSTRETCHBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRSTRETCHBLT::iUsageSrc)
            .property("offBmiSrc", &EMRSTRETCHBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRSTRETCHBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRSTRETCHBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRSTRETCHBLT::cbBitsSrc)
            .property("cxSrc", &EMRSTRETCHBLT::cxSrc)
            .property("cySrc", &EMRSTRETCHBLT::cySrc)
            ,
        xlb_class<EMRSTRETCHDIBITS>("EMRSTRETCHDIBITS") .constructor() .destructor()
            .property("emr", &EMRSTRETCHDIBITS::emr)
            .property("rclBounds", &EMRSTRETCHDIBITS::rclBounds)
            .property("xDest", &EMRSTRETCHDIBITS::xDest)
            .property("yDest", &EMRSTRETCHDIBITS::yDest)
            .property("xSrc", &EMRSTRETCHDIBITS::xSrc)
            .property("ySrc", &EMRSTRETCHDIBITS::ySrc)
            .property("cxSrc", &EMRSTRETCHDIBITS::cxSrc)
            .property("cySrc", &EMRSTRETCHDIBITS::cySrc)
            .property("offBmiSrc", &EMRSTRETCHDIBITS::offBmiSrc)
            .property("cbBmiSrc", &EMRSTRETCHDIBITS::cbBmiSrc)
            .property("offBitsSrc", &EMRSTRETCHDIBITS::offBitsSrc)
            .property("cbBitsSrc", &EMRSTRETCHDIBITS::cbBitsSrc)
            .property("iUsageSrc", &EMRSTRETCHDIBITS::iUsageSrc)
            .property("dwRop", &EMRSTRETCHDIBITS::dwRop)
            .property("cxDest", &EMRSTRETCHDIBITS::cxDest)
            .property("cyDest", &EMRSTRETCHDIBITS::cyDest)
            ,
        xlb_class<EMRTEXT>("EMRTEXT") .constructor() .destructor()
            .property("ptlReference", &EMRTEXT::ptlReference)
            .property("nChars", &EMRTEXT::nChars)
            .property("offString", &EMRTEXT::offString)
            .property("fOptions", &EMRTEXT::fOptions)
            .property("rcl", &EMRTEXT::rcl)
            .property("offDx", &EMRTEXT::offDx)
            ,
        xlb_class<EMRTRANSPARENTBLT>("EMRTRANSPARENTBLT") .constructor() .destructor()
            .property("emr", &EMRTRANSPARENTBLT::emr)
            .property("rclBounds", &EMRTRANSPARENTBLT::rclBounds)
            .property("xDest", &EMRTRANSPARENTBLT::xDest)
            .property("yDest", &EMRTRANSPARENTBLT::yDest)
            .property("cxDest", &EMRTRANSPARENTBLT::cxDest)
            .property("cyDest", &EMRTRANSPARENTBLT::cyDest)
            .property("dwRop", &EMRTRANSPARENTBLT::dwRop)
            .property("xSrc", &EMRTRANSPARENTBLT::xSrc)
            .property("ySrc", &EMRTRANSPARENTBLT::ySrc)
            .property("xformSrc", &EMRTRANSPARENTBLT::xformSrc)
            .property("crBkColorSrc", &EMRTRANSPARENTBLT::crBkColorSrc)
            .property("iUsageSrc", &EMRTRANSPARENTBLT::iUsageSrc)
            .property("offBmiSrc", &EMRTRANSPARENTBLT::offBmiSrc)
            .property("cbBmiSrc", &EMRTRANSPARENTBLT::cbBmiSrc)
            .property("offBitsSrc", &EMRTRANSPARENTBLT::offBitsSrc)
            .property("cbBitsSrc", &EMRTRANSPARENTBLT::cbBitsSrc)
            .property("cxSrc", &EMRTRANSPARENTBLT::cxSrc)
            .property("cySrc", &EMRTRANSPARENTBLT::cySrc)
            ,
        xlb_class<ENHMETAHEADER>("ENHMETAHEADER") .constructor() .destructor()
            .property("iType", &ENHMETAHEADER::iType)
            .property("nSize", &ENHMETAHEADER::nSize)
            .property("rclBounds", &ENHMETAHEADER::rclBounds)
            .property("rclFrame", &ENHMETAHEADER::rclFrame)
            .property("dSignature", &ENHMETAHEADER::dSignature)
            .property("nVersion", &ENHMETAHEADER::nVersion)
            .property("nBytes", &ENHMETAHEADER::nBytes)
            .property("nRecords", &ENHMETAHEADER::nRecords)
            .property("nHandles", &ENHMETAHEADER::nHandles)
            .property("sReserved", &ENHMETAHEADER::sReserved)
            .property("nDescription", &ENHMETAHEADER::nDescription)
            .property("offDescription", &ENHMETAHEADER::offDescription)
            .property("nPalEntries", &ENHMETAHEADER::nPalEntries)
            .property("szlDevice", &ENHMETAHEADER::szlDevice)
            .property("szlMillimeters", &ENHMETAHEADER::szlMillimeters)
            .property("cbPixelFormat", &ENHMETAHEADER::cbPixelFormat)
            .property("offPixelFormat", &ENHMETAHEADER::offPixelFormat)
            .property("bOpenGL", &ENHMETAHEADER::bOpenGL)
            .property("szlMicrometers", &ENHMETAHEADER::szlMicrometers)
            ,
        xlb_class<ENHMETARECORD>("ENHMETARECORD") .constructor() .destructor()
            .property("iType", &ENHMETARECORD::iType)
            .property("nSize", &ENHMETARECORD::nSize)
            .property("dParm", &ENHMETARECORD::dParm)
            ,
        xlb_class<ENUMLOGFONT>("ENUMLOGFONT") .constructor() .destructor()
            .property("elfLogFont", &ENUMLOGFONT::elfLogFont)
            .property("elfFullName", &ENUMLOGFONT::elfFullName)
            .property("elfStyle", &ENUMLOGFONT::elfStyle)
            ,
        xlb_class<ENUMLOGFONTEX>("ENUMLOGFONTEX") .constructor() .destructor()
            .property("elfLogFont", &ENUMLOGFONTEX::elfLogFont)
            .property("elfFullName", &ENUMLOGFONTEX::elfFullName)
            .property("elfStyle", &ENUMLOGFONTEX::elfStyle)
            .property("elfScript", &ENUMLOGFONTEX::elfScript)
            ,
        xlb_class<ENUMLOGFONTEXDV>("ENUMLOGFONTEXDV") .constructor() .destructor()
            .property("elfEnumLogfontEx", &ENUMLOGFONTEXDV::elfEnumLogfontEx)
            .property("elfDesignVector", &ENUMLOGFONTEXDV::elfDesignVector)
            ,
        xlb_class<ENUMTEXTMETRIC>("ENUMTEXTMETRIC") .constructor() .destructor()
            .property("etmNewTextMetricEx", &ENUMTEXTMETRIC::etmNewTextMetricEx)
            .property("etmAxesList", &ENUMTEXTMETRIC::etmAxesList)
            ,
        xlb_class<EXTLOGFONT>("EXTLOGFONT") .constructor() .destructor()
            .property("elfLogFont", &EXTLOGFONT::elfLogFont)
            .property("elfFullName", &EXTLOGFONT::elfFullName)
            .property("elfStyle", &EXTLOGFONT::elfStyle)
            .property("elfVersion", &EXTLOGFONT::elfVersion)
            .property("elfStyleSize", &EXTLOGFONT::elfStyleSize)
            .property("elfMatch", &EXTLOGFONT::elfMatch)
            .property("elfReserved", &EXTLOGFONT::elfReserved)
            .property("elfVendorId", &EXTLOGFONT::elfVendorId)
            .property("elfCulture", &EXTLOGFONT::elfCulture)
            .property("elfPanose", &EXTLOGFONT::elfPanose)
            ,
        xlb_class<EXTLOGPEN>("EXTLOGPEN") .constructor() .destructor()
            .property("elpPenStyle", &EXTLOGPEN::elpPenStyle)
            .property("elpWidth", &EXTLOGPEN::elpWidth)
            .property("elpBrushStyle", &EXTLOGPEN::elpBrushStyle)
            .property("elpColor", &EXTLOGPEN::elpColor)
            .property("elpHatch", &EXTLOGPEN::elpHatch)
            .property("elpNumEntries", &EXTLOGPEN::elpNumEntries)
            .property("elpStyleEntry", &EXTLOGPEN::elpStyleEntry)
            ,
        xlb_class<FIXED>("FIXED") .constructor() .destructor()
            .property("fract", &FIXED::fract)
            .property("value", &FIXED::value)
            ,
        xlb_class<GCP_RESULTS>("GCP_RESULTS") .constructor() .destructor()
            .property("lStructSize", &GCP_RESULTS::lStructSize)
            .property("lpOutString", &GCP_RESULTS::lpOutString)
            .property("lpOrder", &GCP_RESULTS::lpOrder)
            .property("lpDx", &GCP_RESULTS::lpDx)
            .property("lpCaretPos", &GCP_RESULTS::lpCaretPos)
            .property("lpClass", &GCP_RESULTS::lpClass)
            .property("lpGlyphs", &GCP_RESULTS::lpGlyphs)
            .property("nGlyphs", &GCP_RESULTS::nGlyphs)
            .property("nMaxFit", &GCP_RESULTS::nMaxFit)
            ,
        xlb_class<GLYPHMETRICS>("GLYPHMETRICS") .constructor() .destructor()
            .property("gmBlackBoxX", &GLYPHMETRICS::gmBlackBoxX)
            .property("gmBlackBoxY", &GLYPHMETRICS::gmBlackBoxY)
            .property("gmptGlyphOrigin", &GLYPHMETRICS::gmptGlyphOrigin)
            .property("gmCellIncX", &GLYPHMETRICS::gmCellIncX)
            .property("gmCellIncY", &GLYPHMETRICS::gmCellIncY)
            ,
        xlb_class<GLYPHSET>("GLYPHSET") .constructor() .destructor()
            .property("cbThis", &GLYPHSET::cbThis)
            .property("flAccel", &GLYPHSET::flAccel)
            .property("cGlyphsSupported", &GLYPHSET::cGlyphsSupported)
            .property("cRanges", &GLYPHSET::cRanges)
            .property("ranges", &GLYPHSET::ranges)
            ,
        xlb_class<GRADIENT_RECT>("GRADIENT_RECT") .constructor() .destructor()
            .property("UpperLeft", &GRADIENT_RECT::UpperLeft)
            .property("LowerRight", &GRADIENT_RECT::LowerRight)
            ,
        xlb_class<GRADIENT_TRIANGLE>("GRADIENT_TRIANGLE") .constructor() .destructor()
            .property("Vertex1", &GRADIENT_TRIANGLE::Vertex1)
            .property("Vertex2", &GRADIENT_TRIANGLE::Vertex2)
            .property("Vertex3", &GRADIENT_TRIANGLE::Vertex3)
            ,
        xlb_class<HANDLETABLE>("HANDLETABLE") .constructor() .destructor()
            .property("objectHandle", &HANDLETABLE::objectHandle)
            ,
        xlb_class<KERNINGPAIR>("KERNINGPAIR") .constructor() .destructor()
            .property("wFirst", &KERNINGPAIR::wFirst)
            .property("wSecond", &KERNINGPAIR::wSecond)
            .property("iKernAmount", &KERNINGPAIR::iKernAmount)
            ,
        xlb_class<LOGBRUSH>("LOGBRUSH") .constructor() .destructor()
            .property("lbStyle", &LOGBRUSH::lbStyle)
            .property("lbColor", &LOGBRUSH::lbColor)
            .property("lbHatch", &LOGBRUSH::lbHatch)
            ,
        xlb_class<LOGBRUSH32>("LOGBRUSH32") .constructor() .destructor()
            .property("lbStyle", &LOGBRUSH32::lbStyle)
            .property("lbColor", &LOGBRUSH32::lbColor)
            .property("lbHatch", &LOGBRUSH32::lbHatch)
            ,
        xlb_class<LOGFONT>("LOGFONT") .constructor() .destructor()
            .property("lfHeight", &LOGFONT::lfHeight)
            .property("lfWidth", &LOGFONT::lfWidth)
            .property("lfEscapement", &LOGFONT::lfEscapement)
            .property("lfOrientation", &LOGFONT::lfOrientation)
            .property("lfWeight", &LOGFONT::lfWeight)
            .property("lfItalic", &LOGFONT::lfItalic)
            .property("lfUnderline", &LOGFONT::lfUnderline)
            .property("lfStrikeOut", &LOGFONT::lfStrikeOut)
            .property("lfCharSet", &LOGFONT::lfCharSet)
            .property("lfOutPrecision", &LOGFONT::lfOutPrecision)
            .property("lfClipPrecision", &LOGFONT::lfClipPrecision)
            .property("lfQuality", &LOGFONT::lfQuality)
            .property("lfPitchAndFamily", &LOGFONT::lfPitchAndFamily)
            .property("lfFaceName", &LOGFONT::lfFaceName)
            ,
        xlb_class<LOGPALETTE>("LOGPALETTE") .constructor() .destructor()
            .property("palVersion", &LOGPALETTE::palVersion)
            .property("palNumEntries", &LOGPALETTE::palNumEntries)
            .property("palPalEntry", &LOGPALETTE::palPalEntry)
            ,
        xlb_class<LOGPEN>("LOGPEN") .constructor() .destructor()
            .property("lopnStyle", &LOGPEN::lopnStyle)
            .property("lopnWidth", &LOGPEN::lopnWidth)
            .property("lopnColor", &LOGPEN::lopnColor)
            ,
        xlb_class<MAT2>("MAT2") .constructor() .destructor()
            .property("eM11", &MAT2::eM11)
            .property("eM12", &MAT2::eM12)
            .property("eM21", &MAT2::eM21)
            .property("eM22", &MAT2::eM22)
            ,
        xlb_class<METAHEADER>("METAHEADER") .constructor() .destructor()
            .property("mtType", &METAHEADER::mtType)
            .property("mtHeaderSize", &METAHEADER::mtHeaderSize)
            .property("mtVersion", &METAHEADER::mtVersion)
            .property("mtSize", &METAHEADER::mtSize)
            .property("mtNoObjects", &METAHEADER::mtNoObjects)
            .property("mtMaxRecord", &METAHEADER::mtMaxRecord)
            .property("mtNoParameters", &METAHEADER::mtNoParameters)
            ,
        xlb_class<METARECORD>("METARECORD") .constructor() .destructor()
            .property("rdSize", &METARECORD::rdSize)
            .property("rdFunction", &METARECORD::rdFunction)
            .property("rdParm", &METARECORD::rdParm)
            ,
        xlb_class<MONITORINFO>("MONITORINFO") .constructor() .destructor()
            .property("cbSize", &MONITORINFO::cbSize)
            .property("rcMonitor", &MONITORINFO::rcMonitor)
            .property("rcWork", &MONITORINFO::rcWork)
            .property("dwFlags", &MONITORINFO::dwFlags)
            ,
        xlb_class<MONITORINFOEX>("MONITORINFOEX") .constructor() .destructor()
            .inherited<MONITORINFO>()
            .property("szDevice", &MONITORINFOEX::szDevice)
            //.property("tagMONITORINFO", &MONITORINFOEX::tagMONITORINFO)
            ,
        xlb_class<NEWTEXTMETRIC>("NEWTEXTMETRIC") .constructor() .destructor()
            .property("tmHeight", &NEWTEXTMETRIC::tmHeight)
            .property("tmAscent", &NEWTEXTMETRIC::tmAscent)
            .property("tmDescent", &NEWTEXTMETRIC::tmDescent)
            .property("tmInternalLeading", &NEWTEXTMETRIC::tmInternalLeading)
            .property("tmExternalLeading", &NEWTEXTMETRIC::tmExternalLeading)
            .property("tmAveCharWidth", &NEWTEXTMETRIC::tmAveCharWidth)
            .property("tmMaxCharWidth", &NEWTEXTMETRIC::tmMaxCharWidth)
            .property("tmWeight", &NEWTEXTMETRIC::tmWeight)
            .property("tmOverhang", &NEWTEXTMETRIC::tmOverhang)
            .property("tmDigitizedAspectX", &NEWTEXTMETRIC::tmDigitizedAspectX)
            .property("tmDigitizedAspectY", &NEWTEXTMETRIC::tmDigitizedAspectY)
            .property("tmFirstChar", &NEWTEXTMETRIC::tmFirstChar)
            .property("tmLastChar", &NEWTEXTMETRIC::tmLastChar)
            .property("tmDefaultChar", &NEWTEXTMETRIC::tmDefaultChar)
            .property("tmBreakChar", &NEWTEXTMETRIC::tmBreakChar)
            .property("tmItalic", &NEWTEXTMETRIC::tmItalic)
            .property("tmUnderlined", &NEWTEXTMETRIC::tmUnderlined)
            .property("tmStruckOut", &NEWTEXTMETRIC::tmStruckOut)
            .property("tmPitchAndFamily", &NEWTEXTMETRIC::tmPitchAndFamily)
            .property("tmCharSet", &NEWTEXTMETRIC::tmCharSet)
            .property("ntmFlags", &NEWTEXTMETRIC::ntmFlags)
            .property("ntmSizeEM", &NEWTEXTMETRIC::ntmSizeEM)
            .property("ntmCellHeight", &NEWTEXTMETRIC::ntmCellHeight)
            .property("ntmAvgWidth", &NEWTEXTMETRIC::ntmAvgWidth)
            ,
        xlb_class<NEWTEXTMETRICEX>("NEWTEXTMETRICEX") .constructor() .destructor()
            .property("ntmTm", &NEWTEXTMETRICEX::ntmTm)
            .property("ntmFontSig", &NEWTEXTMETRICEX::ntmFontSig)
            ,
        xlb_class<OUTLINETEXTMETRIC>("OUTLINETEXTMETRIC") .constructor() .destructor()
            .property("otmSize", &OUTLINETEXTMETRIC::otmSize)
            .property("otmTextMetrics", &OUTLINETEXTMETRIC::otmTextMetrics)
            .property("otmFiller", &OUTLINETEXTMETRIC::otmFiller)
            .property("otmPanoseNumber", &OUTLINETEXTMETRIC::otmPanoseNumber)
            .property("otmfsSelection", &OUTLINETEXTMETRIC::otmfsSelection)
            .property("otmfsType", &OUTLINETEXTMETRIC::otmfsType)
            .property("otmsCharSlopeRise", &OUTLINETEXTMETRIC::otmsCharSlopeRise)
            .property("otmsCharSlopeRun", &OUTLINETEXTMETRIC::otmsCharSlopeRun)
            .property("otmItalicAngle", &OUTLINETEXTMETRIC::otmItalicAngle)
            .property("otmEMSquare", &OUTLINETEXTMETRIC::otmEMSquare)
            .property("otmAscent", &OUTLINETEXTMETRIC::otmAscent)
            .property("otmDescent", &OUTLINETEXTMETRIC::otmDescent)
            .property("otmLineGap", &OUTLINETEXTMETRIC::otmLineGap)
            .property("otmsCapEmHeight", &OUTLINETEXTMETRIC::otmsCapEmHeight)
            .property("otmsXHeight", &OUTLINETEXTMETRIC::otmsXHeight)
            .property("otmrcFontBox", &OUTLINETEXTMETRIC::otmrcFontBox)
            .property("otmMacAscent", &OUTLINETEXTMETRIC::otmMacAscent)
            .property("otmMacDescent", &OUTLINETEXTMETRIC::otmMacDescent)
            .property("otmMacLineGap", &OUTLINETEXTMETRIC::otmMacLineGap)
            .property("otmusMinimumPPEM", &OUTLINETEXTMETRIC::otmusMinimumPPEM)
            .property("otmptSubscriptSize", &OUTLINETEXTMETRIC::otmptSubscriptSize)
            .property("otmptSubscriptOffset", &OUTLINETEXTMETRIC::otmptSubscriptOffset)
            .property("otmptSuperscriptSize", &OUTLINETEXTMETRIC::otmptSuperscriptSize)
            .property("otmptSuperscriptOffset", &OUTLINETEXTMETRIC::otmptSuperscriptOffset)
            .property("otmsStrikeoutSize", &OUTLINETEXTMETRIC::otmsStrikeoutSize)
            .property("otmsStrikeoutPosition", &OUTLINETEXTMETRIC::otmsStrikeoutPosition)
            .property("otmsUnderscoreSize", &OUTLINETEXTMETRIC::otmsUnderscoreSize)
            .property("otmsUnderscorePosition", &OUTLINETEXTMETRIC::otmsUnderscorePosition)
            .property("otmpFamilyName", &OUTLINETEXTMETRIC::otmpFamilyName)
            .property("otmpFaceName", &OUTLINETEXTMETRIC::otmpFaceName)
            .property("otmpStyleName", &OUTLINETEXTMETRIC::otmpStyleName)
            .property("otmpFullName", &OUTLINETEXTMETRIC::otmpFullName)
            ,
        xlb_class<PAINTSTRUCT>("PAINTSTRUCT") .constructor() .destructor()
            .property("hdc", &PAINTSTRUCT::hdc)
            .property("fErase", &PAINTSTRUCT::fErase)
            .property("rcPaint", &PAINTSTRUCT::rcPaint)
            .property("fRestore", &PAINTSTRUCT::fRestore)
            .property("fIncUpdate", &PAINTSTRUCT::fIncUpdate)
            .property("rgbReserved", &PAINTSTRUCT::rgbReserved)
            ,
        xlb_class<PANOSE>("PANOSE") .constructor() .destructor()
            .property("bFamilyType", &PANOSE::bFamilyType)
            .property("bSerifStyle", &PANOSE::bSerifStyle)
            .property("bWeight", &PANOSE::bWeight)
            .property("bProportion", &PANOSE::bProportion)
            .property("bContrast", &PANOSE::bContrast)
            .property("bStrokeVariation", &PANOSE::bStrokeVariation)
            .property("bArmStyle", &PANOSE::bArmStyle)
            .property("bLetterform", &PANOSE::bLetterform)
            .property("bMidline", &PANOSE::bMidline)
            .property("bXHeight", &PANOSE::bXHeight)
            ,
        xlb_class<POINTFX>("POINTFX") .constructor() .destructor()
            .property("x", &POINTFX::x)
            .property("y", &POINTFX::y)
            ,
        xlb_class<POLYTEXTA>("POLYTEXTA") .constructor() .destructor()
            .property("x", &POLYTEXTA::x)
            .property("y", &POLYTEXTA::y)
            .property("n", &POLYTEXTA::n)
            .property("lpstr", &POLYTEXTA::lpstr)
            .property("uiFlags", &POLYTEXTA::uiFlags)
            .property("rcl", &POLYTEXTA::rcl)
            .property("pdx", &POLYTEXTA::pdx)
            ,
        xlb_class<RASTERIZER_STATUS>("RASTERIZER_STATUS") .constructor() .destructor()
            .property("nSize", &RASTERIZER_STATUS::nSize)
            .property("wFlags", &RASTERIZER_STATUS::wFlags)
            .property("nLanguageID", &RASTERIZER_STATUS::nLanguageID)
            ,
        xlb_class<RGBQUAD>("RGBQUAD") .constructor() .destructor()
            .property("rgbBlue", &RGBQUAD::rgbBlue)
            .property("rgbGreen", &RGBQUAD::rgbGreen)
            .property("rgbRed", &RGBQUAD::rgbRed)
            .property("rgbReserved", &RGBQUAD::rgbReserved)
            ,
        xlb_class<RGBTRIPLE>("RGBTRIPLE") .constructor() .destructor()
            .property("rgbtBlue", &RGBTRIPLE::rgbtBlue)
            .property("rgbtGreen", &RGBTRIPLE::rgbtGreen)
            .property("rgbtRed", &RGBTRIPLE::rgbtRed)
            ,
        xlb_class<RGNDATA>("RGNDATA") .constructor() .destructor()
            .property("rdh", &RGNDATA::rdh)
            .property("Buffer", &RGNDATA::Buffer)
            ,
        xlb_class<RGNDATAHEADER>("RGNDATAHEADER") .constructor() .destructor()
            .property("dwSize", &RGNDATAHEADER::dwSize)
            .property("iType", &RGNDATAHEADER::iType)
            .property("nCount", &RGNDATAHEADER::nCount)
            .property("nRgnSize", &RGNDATAHEADER::nRgnSize)
            .property("rcBound", &RGNDATAHEADER::rcBound)
            ,
        xlb_class<TEXTMETRIC>("TEXTMETRIC") .constructor() .destructor()
            .property("tmHeight", &TEXTMETRIC::tmHeight)
            .property("tmAscent", &TEXTMETRIC::tmAscent)
            .property("tmDescent", &TEXTMETRIC::tmDescent)
            .property("tmInternalLeading", &TEXTMETRIC::tmInternalLeading)
            .property("tmExternalLeading", &TEXTMETRIC::tmExternalLeading)
            .property("tmAveCharWidth", &TEXTMETRIC::tmAveCharWidth)
            .property("tmMaxCharWidth", &TEXTMETRIC::tmMaxCharWidth)
            .property("tmWeight", &TEXTMETRIC::tmWeight)
            .property("tmOverhang", &TEXTMETRIC::tmOverhang)
            .property("tmDigitizedAspectX", &TEXTMETRIC::tmDigitizedAspectX)
            .property("tmDigitizedAspectY", &TEXTMETRIC::tmDigitizedAspectY)
            .property("tmFirstChar", &TEXTMETRIC::tmFirstChar)
            .property("tmLastChar", &TEXTMETRIC::tmLastChar)
            .property("tmDefaultChar", &TEXTMETRIC::tmDefaultChar)
            .property("tmBreakChar", &TEXTMETRIC::tmBreakChar)
            .property("tmItalic", &TEXTMETRIC::tmItalic)
            .property("tmUnderlined", &TEXTMETRIC::tmUnderlined)
            .property("tmStruckOut", &TEXTMETRIC::tmStruckOut)
            .property("tmPitchAndFamily", &TEXTMETRIC::tmPitchAndFamily)
            .property("tmCharSet", &TEXTMETRIC::tmCharSet)
            ,
        xlb_class<TRIVERTEX>("TRIVERTEX") .constructor() .destructor()
            .property("x", &TRIVERTEX::x)
            .property("y", &TRIVERTEX::y)
            .property("Red", &TRIVERTEX::Red)
            .property("Green", &TRIVERTEX::Green)
            .property("Blue", &TRIVERTEX::Blue)
            .property("Alpha", &TRIVERTEX::Alpha)
            ,
        xlb_class<TTEMBEDINFO>("TTEMBEDINFO") .constructor() .destructor()
            .property("usStructSize", &TTEMBEDINFO::usStructSize)
            .property("usRootStrSize", &TTEMBEDINFO::usRootStrSize)
            .property("pusRootStr", &TTEMBEDINFO::pusRootStr)
            ,
        xlb_class<TTLOADINFO>("TTLOADINFO") .constructor() .destructor()
            .property("usStructSize", &TTLOADINFO::usStructSize)
            .property("usRefStrSize", &TTLOADINFO::usRefStrSize)
            .property("pusRefStr", &TTLOADINFO::pusRefStr)
            ,
        xlb_class<TTPOLYCURVE>("TTPOLYCURVE") .constructor() .destructor()
            .property("wType", &TTPOLYCURVE::wType)
            .property("cpfx", &TTPOLYCURVE::cpfx)
            .property("apfx", &TTPOLYCURVE::apfx)
            ,
        xlb_class<TTPOLYGONHEADER>("TTPOLYGONHEADER") .constructor() .destructor()
            .property("cb", &TTPOLYGONHEADER::cb)
            .property("dwType", &TTPOLYGONHEADER::dwType)
            .property("pfxStart", &TTPOLYGONHEADER::pfxStart)
            ,
        xlb_class<TTVALIDATIONTESTSPARAMS>("TTVALIDATIONTESTSPARAMS") .constructor() .destructor()
            .property("ulStructSize", &TTVALIDATIONTESTSPARAMS::ulStructSize)
            .property("lTestFromSize", &TTVALIDATIONTESTSPARAMS::lTestFromSize)
            .property("lTestToSize", &TTVALIDATIONTESTSPARAMS::lTestToSize)
            .property("ulCharSet", &TTVALIDATIONTESTSPARAMS::ulCharSet)
            .property("usReserved1", &TTVALIDATIONTESTSPARAMS::usReserved1)
            .property("usCharCodeCount", &TTVALIDATIONTESTSPARAMS::usCharCodeCount)
            .property("pusCharCodeSet", &TTVALIDATIONTESTSPARAMS::pusCharCodeSet)
            ,
        xlb_class<TTVALIDATIONTESTSPARAMSEX>("TTVALIDATIONTESTSPARAMSEX") .constructor() .destructor()
            .property("ulStructSize", &TTVALIDATIONTESTSPARAMSEX::ulStructSize)
            .property("lTestFromSize", &TTVALIDATIONTESTSPARAMSEX::lTestFromSize)
            .property("lTestToSize", &TTVALIDATIONTESTSPARAMSEX::lTestToSize)
            .property("ulCharSet", &TTVALIDATIONTESTSPARAMSEX::ulCharSet)
            .property("usReserved1", &TTVALIDATIONTESTSPARAMSEX::usReserved1)
            .property("usCharCodeCount", &TTVALIDATIONTESTSPARAMSEX::usCharCodeCount)
            .property("pulCharCodeSet", &TTVALIDATIONTESTSPARAMSEX::pulCharCodeSet)
            ,
        xlb_class<WCRANGE>("WCRANGE") .constructor() .destructor()
            .property("wcLow", &WCRANGE::wcLow)
            .property("cGlyphs", &WCRANGE::cGlyphs)
            ,
        xlb_class<XFORM>("XFORM") .constructor() .destructor()
            .property("eM11", &XFORM::eM11)
            .property("eM12", &XFORM::eM12)
            .property("eM21", &XFORM::eM21)
            .property("eM22", &XFORM::eM22)
            .property("eDx", &XFORM::eDx)
            .property("eDy", &XFORM::eDy)
    });
#endif // defined(BIND_GDI)

    return 0;
} // load_gdi
