; ModuleID = 'internal.cpp'
source_filename = "internal.cpp"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.29.30038"

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local noundef i32 @"?foo2@@YAHXZ"() #0 {
  %1 = call noundef i32 @"?func@@YAHXZ"()
  %2 = call noundef i32 @"?foo@?A0x6479AED9@@YAHXZ"()
  %3 = add nsw i32 %1, %2
  ret i32 %3
}

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define internal noundef i32 @"?func@@YAHXZ"() #1 {
  ret i32 3
}

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define internal noundef i32 @"?foo@?A0x6479AED9@@YAHXZ"() #1 {
  ret i32 42
}

attributes #0 = { mustprogress noinline optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress noinline nounwind optnone uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 1, !"MaxTLSAlign", i32 65536}
!4 = !{!"clang version 17.0.1"}
